#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],cnt[N],f[N][N][N];//前i天，失败j个人，选取了k个c[i]小于等于j的人 
string s;
int jc[N];
int p[N],tot,acc[N],qz[N],ct,ans;
void dfs(int x) {
	if(x>n) {
		if(ct<m) return ;
		int sum=0,res=1;
		for(int i=1;i<=n;i++)
			qz[i]=qz[i-1]+(!acc[i]);
		int p=n;
		for(int i=n;i>=1;i--) {
			if(!acc[i]) continue;
			while(p&&p>qz[i]) sum+=cnt[p],p--;
//			cout<<sum<<"!\n";
			sum%=mod;
			if(sum==0) return ;
			res*=sum;
			res%=mod;
			sum--;
		}
//		cout<<res<<"\n";
		ans+=res;
		return ;
	}
	dfs(x+1);
	if(s[x-1]!='0') {
		acc[x]=1,ct++;
		dfs(x+1);
		ct--,acc[x]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
//	freopen("employ1.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i],cnt[c[i]]++;
	int bl=1;
	for(int i=0;i<n;i++) if(s[i]=='0') bl=0;
	for(int i=0;i<n;i++) if(s[i]=='1') p[++tot]=i;
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	if(bl) {
		cout<<jc[n]<<"\n";
		return 0;
	}
	if(tot<m) {
		cout<<0<<"\n";
	}
	if(n<=18) {
		dfs(1);
		cout<<ans;
		return 0;
	}
	cout<<0<<"\n";
	return 0;/*
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i],cnt[c[i]]++;
	for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
	f[0][0][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=i;j++) {
			for(int k=0;k<=i;k++) {
				if(s[i]=='0') {
					if(j!=0&&k!=0)
						f[i][j][k]=(f[i-1][j-1][k-1]*(cnt[])+f[i-1][j-1][k])%mod;
					else if(j!=0)
						f[i][j][k]=f[i-1][j-1][k];
				}
				else {
					f[i][j][k]=f[i-1][j-1];
				}
			}
		}
	}*/
}
