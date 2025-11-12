#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	/*
	
	突然想起来有中文
	I write the text in English for 10min(at least)!!!
	
	for(;;)cout<<"我要丸战双QWQ"<<'\n';
	
	欢迎回来，开拓者 => 研究 => 15=5 => 我一直在哭
	 
	*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int e=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	bool flag=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==e){
			cout<<c<<" "<<r;
			break;
		}
		if(flag && r==n){
			c++;
			flag=0;
		}
		else if(!flag && r==1){
			c++;
			flag=1;
		}
		else if(!flag)r--;
		else r++;
		
		
	}
	return 0;
}
