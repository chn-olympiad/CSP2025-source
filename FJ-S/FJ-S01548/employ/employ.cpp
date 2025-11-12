#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int del(int x,int y){
	return x-y<0?x-y+mod:x-y;
}
int n,m,c[505],a[505],f[505],g[505],jc[505],inv[505],p[505],ANS,h[1<<18][19];
char s[505];
bool bo[505];
inline int C(int n,int m){
	return 1ll*jc[n]*inv[m]%mod*inv[n-m]%mod;
}
inline void dfs(int x){
	if(x==n+1){
		int now=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'){
				++now;
				continue;
			}
			int x=0;
			if(now>=c[p[i]]){
				++now;
				x^=1;
			}
			int num=0;
			for(int j=1;j<i;++j)if(c[p[j]]<c[p[i]])++num;
			if(num>=c[p[i]]){
				x^=1;
			}
			if(x){
				cout<<i<<endl;
				for(int i=1;i<=n;++i)cout<<p[i]<<' ';
				exit(0);
			}
		}
		if(n-now>=m)++ANS;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!bo[i]){
			p[x]=i;
			bo[i]=1;
			dfs(x+1);
			bo[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	if(n<=18){
		h[0][0]=1;
		for(int S=0;S<((1<<n)-1);++S){
			for(int i=__builtin_popcount(S);i>=0;--i){
				for(int j=0;j<n;++j){
					if((S>>j)&1)continue;
					if(i>=c[j+1]||s[__builtin_popcount(S)+1]=='0')h[S|(1<<j)][i+1]=add(h[S|(1<<j)][i+1],h[S][i]);
					else h[S|(1<<j)][i]=add(h[S|(1<<j)][i],h[S][i]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;++i)ans=add(ans,h[(1<<n)-1][i]);
		cout<<ans<<endl;
		return 0;
	}
	if(m==n){
		bool cm=1;
		for(int i=1;i<=n;++i)if(s[i]=='0'||c[i]==0)cm=0;
		if(cm){
			int ans=1;
			for(int i=1;i<=n;++i)ans=1ll*ans*i%mod;
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	jc[0]=jc[1]=1;
	for(int i=2;i<=n;++i)jc[i]=1ll*jc[i-1]*i%mod; 
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;++i)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	if(m==1){
		sort(c+1,c+n+1);
		reverse(c+1,c+n+1);
		int num=0;
		for(int i=1;i<=n;++i)if(s[i]=='1')p[++num]=i;
		f[0]=1;
		for(int i=1;i<=n;++i){
			int xp=num+1;
			for(int j=1;j<=num;++j)if(p[j]-1>=c[i]){
				xp=j;
				break;
			}
			xp=num-xp+1;
			memset(g,0,sizeof(g));
			for(int j=0;j<i;++j){
				if(i-1-j>n-num)continue;
				int k=n-num-(i-1-j);
				g[j]=add(g[j],1ll*f[j]*k%mod);
				if(xp>j)g[j+1]=add(g[j+1],1ll*f[j]*(xp-j)%mod);
			}			
			for(int j=0;j<=i;++j)f[j]=g[j];
		}
		cout<<del(jc[n],f[num])<<endl;
		return 0;
	}
	bool cm=1;
	for(int i=1;i<=n;++i)if(s[i]=='0')cm=0;
	for(int i=1;i<=n;++i)++a[c[i]];
	if(cm){
		f[0]=1;
		int now=a[0];
		for(int i=1;i<=n;++i){
			memset(g,0,sizeof(g));
			for(int j=0;j<=now;++j){
				if(now<i){
					g[j+a[i]]=add(g[j+a[i]],1ll*f[j]*C(now+a[i],a[i])%mod);
				}
				else{
					for(int k=0;k<=a[i];++k){
						g[j+k]=add(g[j+k],1ll*f[j]*C(k+i-1,i-1)%mod*C(a[i]-k+now-i,now-i)%mod);
					}
				}
			}
			now+=a[i];
			for(int j=0;j<=now;++j)f[j]=g[j];
			for(int j=0;j<=now;++j)cout<<f[j]<<' ';
			cout<<endl;
		}
		int ans=0;
		for(int i=m;i<=n;++i)ans=add(ans,f[i]);
		cout<<ans<<endl;
		for(int i=0;i<=n;++i)ans=1ll*ans*jc[a[i]]%mod;
		cout<<ans;
		return 0;
	}
}
