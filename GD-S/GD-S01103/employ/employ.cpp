#include<bits/stdc++.h>
#define ll long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
char Begin;
int read(){
	int num=0;
	char ch;ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58){
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}return num;
}
int read01(){
	char ch;ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	return ch^48;
}
const int N=515;
const int mod=998244353;
ll inv[N],fac[N],ifac[N];
int C(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int iC(int x,int y){
	if(x<0||y<0||x<y)return 0;
	return 1ll*ifac[x]*fac[y]%mod*fac[x-y]%mod;
}
int n,m;
int a[N],s[N];
int f[N][N],ans;
int g[N][N];
void Add(int &x,ll v){x+=v;x-=(x<mod?0:mod);}
char End;
int main(){
	// std::cerr<<(&End-&Begin)/1024/1024<<std::endl;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	inv[0]=inv[1]=fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	fr(i,2,500){
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		fac[i]=1ll*fac[i-1]*i%mod;
		ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
	}
	n=read(),m=read();
	fr(i,1,n)a[i]=read01();
	fr(i,1,n)s[read()]++;
	fr(i,1,n)s[i]+=s[i-1];
	f[0][s[0]]=1;
	fr(i,1,n){
		fr(j,0,i)fr(k,0,s[j]){
			if(!f[j][k])continue;
			ll val=f[j][k];
			if(a[i]){
				if(n-i+1-k>0)Add(g[j][k],1ll*val*(n-i+1-k)%mod);
				if(k)fr(h,0,s[j+1]-s[j]){
					ll V=1ll*val*iC(n-s[j],i-1-s[j]+k)%mod;
					V=1ll*V*C(s[j+1]-s[j],h)%mod;
					V=1ll*V*C(n-s[j+1],i-1-s[j]+k-h)%mod;
					Add(g[j+1][k+s[j+1]-s[j]-h-1],1ll*V*k%mod);
				}
			}else{
				fr(h,0,s[j+1]-s[j]){
					ll V=1ll*val*iC(n-s[j],i-1-s[j]+k)%mod;
					V=1ll*V*C(s[j+1]-s[j],h)%mod;
					V=1ll*V*C(n-s[j+1],i-1-s[j]+k-h)%mod;
					if(n-i+1-k-s[j+1]+s[j]+h>0)
						Add(g[j+1][k+s[j+1]-s[j]-h],1ll*V*(n-i+1-k-s[j+1]+s[j]+h)%mod);
					if(k+s[j+1]-s[j]-h>0)
						Add(g[j+1][k+s[j+1]-s[j]-h-1],1ll*V*(k+s[j+1]-s[j]-h)%mod);
				}
			}
		}
		fr(j,0,i)
			fr(k,0,s[j]){
				f[j][k]=g[j][k];
				g[j][k]=0;
			}
	}
	fr(i,0,n-m){
		ans+=f[i][0];
		ans-=(ans<mod?0:mod);
	}
	printf("%d",ans);
}