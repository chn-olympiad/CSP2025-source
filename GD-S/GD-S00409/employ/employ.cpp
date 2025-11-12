#include<bits/stdc++.h>
#define int long long
#define _ 505
#define mod 998244353
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,m,s[_],p[_],c[_],ans,cntc[_],jc[_];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read(),jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%mod; 
	for(int i=1;i<=n;i++){char c;cin>>c;s[i]=c-'0';}
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=18){
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int cnt=0,ref=0;
			for(int i=1;i<=n;i++){
				if(s[i]==0)++ref;
				else{
					if(ref>=c[p[i]])++ref;
					else ++cnt;
				}
			}
			ans+=(cnt>=m);
		}while(next_permutation(p+1,p+n+1));
		printf("%lld\n",ans);
	}else if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				puts("0");
				return 0;
			}
		}
		printf("%lld\n",jc[n]);
	}else if(m==1){
		for(int i=1;i<=n;i++)cntc[c[i]]++;
		int now=0,res=1,cnt0=0;
		for(int i=1;i<=n;i++){
			now+=cntc[i-1];
			if(s[i]==1){
				if(now==0){res=0;break;}
				res=res*now%mod;
				--now;	
			}else ++cnt0;
		}
		for(int i=1;i<=cnt0;i++)res=res*i%mod;
		if(cntc[n])res=0;
		printf("%lld\n",(jc[n]+mod-res)%mod);
	}
	return 0;
}
