#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
using LL=long long;
inline int read(){
	int x=0,f=1; char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int n,m,c[505];
char is[505];
int id[11];
int f[505][505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",is+1);
	for (int i=1;i<=n;i++) c[i]=read();
	if (m==n){
		bool F=1; int fn=1;
		for (int i=1;i<=n;i++) if (is[i]=='0') F=0;
		for (int i=1;i<=n;i++) if (!c[i]) F=0;
		if (!F) return !printf("0");
		for (int i=1;i<=n;i++) fn=1ll*fn*i%mod;
		printf("%d",fn); return 0;
	}
	if (n<=10){
		for (int i=1;i<=n;i++) id[i]=i;
		int ans=0;
		do{
			int cc=0;
			for (int i=1;i<=n;i++)
				if (cc>=c[id[i]]||is[i]=='0') cc++;
			ans+=(n-cc>=m);
		} while (next_permutation(id+1,id+n+1));
		printf("%d",ans); return 0;
	}
	if (m==1){
		sort(c+1,c+n+1);
		f[1][1]=1;
		for (int i=1;i<=n;i++);
		return 0;
	}
	return 0;
} 
