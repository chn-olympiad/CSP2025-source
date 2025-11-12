#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int B=31;
int n,q;
char s[1010],ta[1010],tb[1010];
int a[1010],b[1010],l[1010],sa[1010],sb[1010],pw[1010],f[1010],g[1010];
int H(){
	int L=strlen(s+1);
	int res=0;
	for(int i=1;i<=L;i++)
		res=res*B%mod+s[i]-'a',res%=mod;
	return res;
}
signed main(){
	freopen("replace1.in","r",stdin);
	
	scanf("%lld%lld",&n,&q);
	pw[0]=1;
	for(int i=1;i<=1001;i++)
		pw[i]=pw[i-1]*B%mod;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1),a[i]=H();
		scanf("%s",s+1),b[i]=H();
		l[i]=strlen(s+1);
	}
	while(q--){
		scanf("%s%s",ta+1,tb+1);
		int L=strlen(ta+1),ans=0;
		for(int i=1;i<=L;i++)
			f[i]=g[i]=0,sa[i]=sa[i-1]*B%mod+ta[i]-'a',sa[i]%=mod;
		for(int i=1;i<=L;i++)
			sb[i]=sb[i-1]*B%mod+tb[i]-'a',sb[i]%=mod;
		f[L+1]=1,g[0]=0;
		for(int i=L;i>=1;i--)
			f[i]=(f[i+1]&(ta[i]==tb[i])); 
		for(int i=1;i<=L;i++)
			g[i]=(g[i-1]&(ta[i]==tb[i]));
		for(int j=1;j<=L;j++){
			for(int i=1;i<=n;i++)
				if(a[i]*pw[j-1]%mod==(sa[j+l[i]-1]-sa[j-1]+mod)%mod)
					if(b[i]*pw[j-1]%mod==(sb[j+l[i]-1]-sb[j-1]+mod)%mod)
						if(f[j+l[i]]&&g[j-1])
						ans++,printf("%d %d\n",j,i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
