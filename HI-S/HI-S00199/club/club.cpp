#include<bits/stdc++.h>
using namespace std;
int t,ans,n;
int h[100005][5];
int dfs(int id,int _ans,int a,int b,int c,int q){
	if(id>=n)return 0;
	int _ans2=0;
	_ans+=h[id][q];
	if(a>0){
		//cout<<"checka "<<id<<" "<<q<<endl;
		_ans2=max(_ans2,dfs(id+1,0,a-1,b,c,1));
	}
	if(b>0){
		//cout<<"checkb "<<id<<" "<<q<<endl;
		_ans2=max(_ans2,dfs(id+1,0,a,b-1,c,2));
	}
	if(c>0){
		//cout<<"checkc "<<id<<" "<<q<<endl;
		_ans2=max(_ans2,dfs(id+1,0,a,b,c-1,3));
	}
	//cout<<"check "<<id<<" "<<q<<" "<<_ans<<" "<<_ans2<<endl;
	return _ans+_ans2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>h[i][1]>>h[i][2]>>h[i][3];
		}
		ans=max(ans,max(dfs(0,0,n/2-1,n/2,n/2,1),max(dfs(0,0,n/2,n/2-1,n/2,2),dfs(0,0,n/2,n/2,n/2-1,3))));
		cout<<ans<<endl;
	}
	return 0;
}
 /*3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0*/
