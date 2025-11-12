#include<cstdio>
#include<cstring>
typedef unsigned long long ULL;
const int N=2e5+10,L=5e6+10;
const ULL B=313;
int n,q;
char s[L];
int m[N];
ULL p[L];
ULL t1[L],t2[L];
ULL s1[N],s2[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')ch=='-'?f=0:0,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?x:-x;
}
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	n=read(),q=read(),p[0]=1;
	for(int i=1;i<L;++i)
		p[i]=p[i-1]*B;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1),m[i]=strlen(s+1);
		for(int j=1;j<=m[i];++j)
			s1[i]=s1[i]*B+(s[j]-'a');
		scanf("%s",s+1);
		for(int j=1;j<=m[i];++j)
			s2[i]=s2[i]*B+(s[j]-'a');
	}
	ULL ans;
	for(int l;q;--q){
		scanf("%s",s+1),l=strlen(s+1),ans=0;
		for(int i=1;i<=l;++i)
			t1[i]=t1[i-1]*B+(s[i]-'a');
		scanf("%s",s+1);
		for(int i=1;i<=l;++i)
			t2[i]=t2[i-1]*B+(s[i]-'a');
		for(int i=1;i<=l;++i)for(int j=1;j<=n;++j)if(i+m[j]-1<=l)
			ans+=(t1[i+m[j]-1]-t1[i-1]*p[m[j]]==s1[j]&&t1[l]-s1[j]*p[i-1]+s2[j]*p[i-1]==t2[l]);
		printf("%llu\n",ans);
	}
	return 0;
}
/*
18:25
25 pts
*/
