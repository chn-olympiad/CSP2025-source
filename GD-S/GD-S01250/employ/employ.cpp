#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
bool flg=true,used[505];
string s;
long long n,m,ans=0,a[505],t[505],c[505];
void dfs(long long x,long long cnt,long long tot){
	if (x>n){
		if (tot>=m)ans=(ans+1)%Mod;
		return;
	}
	for (int i=1;i<=n;i++){
		if (!used[i]){
			a[x]=i,used[i]=true;
			if (t[x]==0)dfs(x+1,cnt+1,tot);
			else if (cnt>=c[i]){
				dfs(x+1,cnt+1,tot);
			}
			else dfs(x+1,cnt,tot+1);
			used[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for (int i=0;i<s.size();i++){
		t[i+1]=s[i]-'0';
		if (t[i+1]==0)flg=false;
	}
	for (int i=1;i<=n;i++)cin>>c[i];
	if (flg==true){
		ans=1;
		for (int i=2;i<=n;i++)ans*=i;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

