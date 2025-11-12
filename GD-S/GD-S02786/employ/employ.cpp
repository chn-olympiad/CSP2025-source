#include<bits/stdc++.h>
using namespace std;
int cnt=0;
const int Mx=5005;
int vis[Mx],pl[Mx],s[Mx],c[Mx],n,m;
void dfs(int dep){
	if(dep==n+1){
		int em=0,fl=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0)fl++;
			else{
				if(fl>=c[pl[i]]){
					fl++;
				}else em++;
			}
		}
		if(em>=m)cnt++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			pl[dep]=i;
			dfs(dep+1); 
			vis[i]=0;
		}
	}
}
char ch;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<cnt;
}
/*
3 2
101
1 1 2
*/
