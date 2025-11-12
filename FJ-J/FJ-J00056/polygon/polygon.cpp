#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int b[5005];
int cnt=0;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int p,int s){
	if(p>n){
		//for(int i=1;i<=s;i++)cout<<b[i]<<" ";
		//cout<<endl;
		if(s>=3){
			int w[s+5];
			for(int i=1;i<=s;i++)w[i]=b[i];
			sort(w+1,w+s+1,cmp);
			int t=w[1]*2,q=0;
			for(int i=1;i<=s;i++){
				q+=w[i];
			}
			//cout<<q<<" "<<t<<endl; 
			if(q>t)cnt++;
			
		}
		
		return ;
	}
	//cout<<1<<endl;
	b[s+1]=a[p];
//	for(int i=1;i<=s;i++)cout<<b[i]<<" ";
//	cout<<endl;
	dfs(p+1,s+1);
	b[s+1]=0;
//	for(int i=1;i<=s;i++)cout<<b[i]<<" ";
//	cout<<endl;
	dfs(p+1,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<cnt<<endl;
	return 0;
}
