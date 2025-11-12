#include<bits/stdc++.h>
using namespace std;
const int MAXN=501;
int n,m;
string q;
int g[MAXN];
bool num;
int ans=1;
int main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
	cin>>n>>m;
	cin>>q;
	for(int c=1;c<=n;c++){
		cin>>g[c];
		if(g[c]==0){
			cout<<0;
			return 0;
		}
	}
	if(n<m){
		cout<<0;
		return 0;
	}
	for(int c=n,i=1;i<=m;i++,c--){
		ans%=998244353;
		c%=998244353;
		ans=(ans*c)%998244353;
	}
	cout<<ans;
}

