#include <bits/stdc++.h>
using namespace std;

const int N=510,mod=998244353;

int n,m,f[20][1<<18],c[N],ones[1<<18],ans;
char s[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<1<<18;i++)
		ones[i]=ones[i-(i&(-i))]+1;
	f[0][0]=1;
	for(int j=0;j<1<<n;j++)
		for(int i=0;i<=n;i++){
			int res=ones[j]-i;
			if(f[i][j]==0)
				continue;
			if(i>=m && j==(1<<n)-1)
				ans=(ans+f[i][j])%mod;
			for(int k=1;k<=n;k++)
				if(!((j>>k-1)&1))
					f[i+(res<c[k] && s[ones[j]+1]=='1')][j|(1<<k-1)]=(f[i+(res<c[k] && s[ones[j]+1]=='1')][j|(1<<k-1)]+f[i][j])%mod;
		}
	printf("%d",ans);
	return 0;
}
