#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0;
string s;
char c[505];
int vis[505];
void dfs(int num,int p,int lu){
	if(num>n && lu>m){
		ans++;
	}
	int w=0,no=0;
	if(s[num-1]==0){
		w=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(p+w<=c[i]){
				no=1;
			}
			dfs(num+1,p+w,lu+no);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans%998244353;
	
	return 0;
}
/*
3 2
101
1 1 2

*/
