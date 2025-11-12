#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int Mod=998244353;
int n,m,ans,c[20],f[20][500005];
bool w[20][500005];
char s[20];
int F(int i,int j){
	int t=__builtin_popcount(j);
	if(i>x) return 0;
	if(j==0) return i==0;
	if(w[i][j]) return f[i][j];
	w[i][j]=true;
	for(int k=0;k<n;k++){
		if(j&(1<<k)==0) continue;
		if(s[t]=='1'&&i<c[k]) f[i][j]+=F(i,j^(1<<k));
		else if(i) f[i][j]+=F(i-1,j^(1<<k));
		f[i][j]%=Mod;
	}
	return f[i][j];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<=n-m;i++){
		ans+=F(i,(1<<n)-1);
		ans%=Mod;
	}
	cout<<ans;
	return 0;
}
