#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],mod=998244353,ans,bol[505];string ss;
void dfs(int x,int s,int f){
	if(x>n){
		if(s>=m)ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!bol[i]){
			bol[i]=1;
			if(f<c[i]){		
				if(ss[x-1]=='1')dfs(x+1,s+1,f);
				if(ss[x-1]=='0')dfs(x+1,s,f+1);
			}
			else dfs(x+1,s,f+1);
			bol[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0,0);cout<<ans;
	return 0;
}
/*
10 1
11111111111
0 0 0 0 0 0 0 0 0 111
*/
