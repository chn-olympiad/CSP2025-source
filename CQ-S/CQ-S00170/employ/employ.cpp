#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
int a[510],b[510];
int f[21][1050010],cnt[1050010];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[i]=c-'0';
	} 
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<j-1)){
				++cnt[i];
			}
		}
		for(int j=1;j<=n;j++){
			if(i&(1<<j-1)){
				for(int k=0;k<=cnt[i];k++){
					if(a[cnt[i]]&&k>0&&cnt[i]-k<b[j]) f[k][i]=(f[k][i]+f[k-1][i^(1<<j-1)])%N;
					if(a[cnt[i]]==0||cnt[i]-k-1>=b[j]) f[k][i]=(f[k][i]+f[k][i^(1<<j-1)])%N;
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) ans=(ans+f[i][(1<<n)-1])%N;
	cout<<ans;
	return 0;
}
