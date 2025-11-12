#include<bits/stdc++.h>
#define ll long long 
using namespace std;
inline int read(){
	int x=0,f=1; char c=0;
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*f;
}
const int N=1010,mod=998244353;
char s[N];
int n,m;
int p[N],c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	int scnt=0,cnt0=0;
	for(int i=1;i<=n;i++){
		scnt+=s[i]-'0';
		c[i]=read();
		if(c[i]==0) cnt0++;
	}
	if(m==n){
		ll fac=1;
		for(int i=1;i<=n;i++) fac*=i,fac%=mod;
		if(scnt==n && !cnt0) printf("%lld\n",fac);
		else puts("0");
	}
	else if(scnt==n){
		if(n-cnt0<m) puts("0");
		else{
			
		}
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			int pre=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='1'){
					if(pre>=c[p[i]]) pre++;
					else cnt++;
				}
				else pre++;
			}
			if(cnt>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}
	return 0;
}
