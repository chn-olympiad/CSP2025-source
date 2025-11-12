#include<bits/stdc++.h>
using namespace std;
namespace IO{
	void read(int &x){
		short f=1;x=0;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
		while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
		x*=f;
		return;
	}
	void out_(int x){
		if(x>9) out_(x/10);
		putchar(x%10+'0');
		return;
	}
	void out(int x){
		if(x<0) putchar('-'),x=-x;
		out_(x);putchar(' ');
		return;
	}
}using namespace IO;
char st;
const int N=505,mod=998244353;
int n,m,a[N],suf[N],f[20][20][(1<<18)];
char str[N];
char ed;
void file(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return;
}
bool sub(){
	for(int i=1;i<=n;i++)
		if(str[i]!='1') return false;
	return true;
}
int main(){
	file();
	read(n),read(m);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) suf[i]=suf[i-1]+(str[i]=='0');
	if(n<=18){
		f[0][0][0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++){
				for(int s=0;s<(1<<n);s++){
					if(f[i][j][s]==0) continue;
					for(int k=1;k<=n;k++){
						if(((s>>(k-1))&1)==0){
							int nx=0;
							if(a[k]>i-j&&str[i+1]=='1') nx=j+1;
							else nx=j;
							f[i+1][nx][s|(1<<(k-1))]=(f[i+1][nx][s|(1<<(k-1))]+f[i][j][s])%mod;
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)
			ans=(ans+f[n][i][(1<<n)-1])%mod;
		out(ans);
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++)
			if(str[i]=='0'||a[i]==0){
				out(0);
				return 0;
			}
		int res=1;
		for(int i=1;i<=n;i++) res=1ll*res*i%mod;
		out(res);
		return 0;
	}
	else out(0);
	return 0;
}

