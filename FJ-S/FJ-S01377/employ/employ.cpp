#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[505],mo=998244353,ans;
string s;
bool fl[505];
void dfs(int x,int cc){
	if(cc>n-m)	return;
	if(x>n){
		ans=(ans+1)%mo;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!fl[i]){
			fl[i]=1;
			if(cc>=a[i]||s[x]=='0')	dfs(x+1,cc+1);
			else	dfs(x+1,cc);
			fl[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<=18){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
