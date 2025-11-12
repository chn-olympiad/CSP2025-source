#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
inline int read(){
	int x=0,f=1; char ch; ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isalnum(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int maxn=500+10,inf=998244353;
int n,m,c[maxn],cnt,pos[maxn],jc[maxn],p[maxn];
char ch[maxn];
inline void work(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read(); scanf("%s",ch+1);
	for(int i=1;i<=n;++i) if(ch[i]=='1') pos[++cnt]=i;
	for(int i=1;i<=n;++i) c[i]=read();
	if(cnt<m) return write(0),void();
	jc[0]=1;
	for(int i=1;i<=n;++i) jc[i]=jc[i-1]*i%inf;
	if(n<=10){
		for(int i=1;i<=n;++i) p[i]=i;
		int ans=0;
		do{
			int sum=0;
			for(int i=1;i<=n;++i) if(ch[i]=='1'&&(i-sum-1)<c[p[i]]) sum++;
			(ans+=sum>=m)%=inf;
		} while(std::next_permutation(p+1,p+1+n));
		write(ans); return ;
	}
	else if(m==n){
		int ans=0;
		for(int i=1;i<=n;++i) if(c[i]) ans++;
		if(ans!=n) write(0);
		else write(jc[n]);
		return ;
	}
	else if(cnt==n){
		int ans=0;
		for(int i=1;i<=n;++i) if(c[i]) ans++;
		write(ans); puts("");
		if(ans<m) write(0);
		else write(jc[n]);
		return ;
	}
}
signed main(){work();return 0;}