#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define mk make_pair
#define N 509
using namespace std;
inline char nc(){static char buf[1<<20],*p=buf,*q=buf;return p==q&&(q=(p=buf)+fread(buf,1,1<<20,stdin),p==q)?EOF:*p++;}
inline ll rd(){bool f=0;char ch=nc();while(ch<'0'||ch>'9')f|=(ch=='-'),ch=nc();ll ans=0;while(ch>='0'&&ch<='9')ans=ans*10+ch-'0',ch=nc();return f?-ans:ans;}
char buf[1<<20],*p3=buf;inline void pc(char c){p3-buf<=1<<20?*p3++=c:(fwrite(buf,1,p3-buf,stdout),p3=buf,*p3++=c);}
inline void wt(ll x){if(x<0)x=-x,pc('-');if(x>9)wt(x/10);pc(x%10+'0');}
const int mod=998244353;
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int n,m,c[N],a[N],b[N],f[N][N];char s[N];
namespace Sub1{
	int f[19][1<<18][19];
	int main(){
		f[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int S=0;S<(1<<n);S++){
				for(int j=0;j<=n;j++){
					if(!f[i][S][j])continue;
					for(int k=0;k<n;k++){
						if((S>>k)&1)continue;
						if(s[i+1]=='0'||j>=c[k+1])f[i+1][S^(1<<k)][j+1]+=f[i][S][j],(f[i+1][S^(1<<k)][j+1]>=mod)&&(f[i+1][S^(1<<k)][j+1]-=mod);
						else f[i+1][S^(1<<k)][j]+=f[i][S][j],(f[i+1][S^(1<<k)][j]>=mod)&&(f[i+1][S^(1<<k)][j]-=mod);
					}
				}
			}
		}
		int ans=0;for(int i=0;i<=m;i++)ans+=f[n][(1<<n)-1][i],(ans>=mod)&&(ans-=mod);
		wt(ans),pc('\n');
		return 0;
	}
}
namespace Sub2{
	int main(){
		bool flag=1;for(int i=1;i<=n;i++)flag&=c[i]>0,flag&=s[i]=='1';
		if(!flag)wt(0),pc('\n');
		else{
			int ans=1;for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
			wt(ans),pc('\n');
		}
		return 0;
	}
}
namespace Sub3{
	int f[N],cnt[N],fc[N],ifc[N];
	inline int C(int n,int m){return 1ll*fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
	int main(){
		fc[0]=1;for(int i=1;i<=n;i++)fc[i]=1ll*fc[i-1]*i%mod;
		ifc[n]=ksm(fc[n],mod-2);for(int i=n;i;i--)ifc[i-1]=1ll*ifc[i]*i%mod;
		int ans=1;for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
		for(int i=1;i<=n;i++)if(s[i]=='1')f[i-1]++;else f[n]++;
		for(int i=1;i<=n;i++)cnt[c[i]]++;
		int ans1=1;
		for(int i=n,res=0;i>=0;i--){
			res+=f[i];
			ans1=1ll*ans1*C(res,cnt[i])%mod*fc[cnt[i]]%mod,res-=cnt[i];
		}
		ans-=ans1,(ans<0)&&(ans+=mod);
		wt(ans),pc('\n');
		return 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("replace4.in","r",stdin);
//	freopen("Mikoto.txt","w",stdout);
	n=rd(),m=rd(),m=n-m;
	char ch=nc();for(int i=1;i<=n;i++){
		while(ch<'0'||ch>'1')ch=nc();
		s[i]=ch,ch=nc();
	}
	for(int i=1;i<=n;i++)c[i]=rd();
	if(n<=18)Sub1::main();
	else if(m==0)Sub2::main();
	else if(m==n-1)Sub3::main();
	fwrite(buf,1,p3-buf,stdout);
	return 0;
}
