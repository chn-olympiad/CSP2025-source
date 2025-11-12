#include<bits/stdc++.h>
#define rd read()
#define int long long
using namespace std;
inline int read()
{
	int x=0,ss=1,s=getchar();
	while((s<'0'||s>'9')&&s!='-')s=getchar();
	if(s=='-')ss=-1,s=getchar();
	while(s>='0'&&s<='9')x=x*10+s-'0',s=getchar();
	return x*ss;
}
const int N=200005,bs=27,mod=100000009;
int n,m;
string s1,s2,t1,t2;
int pw[N],ln[N],hs1[N],hs2[N];
int sum1[N],sum2[N],p[N];
inline bool cmp(int x,int y){return ln[x]>ln[y];}
inline int hs(string s){int x=0;for(int i=0;i<s.size();++i)x=(x*bs+s[i])%mod;return x;}
inline int S1(int l,int r){return (sum1[r]-sum1[l-1]*pw[r-l+1]%mod+mod)%mod;}
inline int S2(int l,int r){return (sum2[r]-sum2[l-1]*pw[r-l+1]%mod+mod)%mod;}
signed main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=pw[i-1]*bs%mod;n=rd,m=rd;
	for(int i=1;i<=n;p[i]=i,++i){cin>>s1>>s2;ln[i]=s1.size(),hs1[i]=hs(s1),hs2[i]=hs(s2);}
	sort(p+1,p+n+1,cmp);
	for(int i=1,q,pmx,smx,ans;i<=m;++i)
	{
		cin>>t1>>t2;q=t1.size(),t1=' '+t1,t2=' '+t2,ans=0;
		for(int j=1;j<=q;++j)sum1[j]=(sum1[j-1]*bs+t1[j])%mod,sum2[j]=(sum2[j-1]*bs+t2[j])%mod;
		for(int j=1;j<=q;++j)if(t1[j]!=t2[j]){pmx=j;break;}for(int j=q;j>=1;--j)if(t1[j]!=t2[j]){smx=j;break;}
		for(int j=smx;j<=q;++j)for(int k=1;k<=n;++k)
		{
			int K=p[k],qw=ln[K];if(j-qw+1>pmx)break;
			if(j>=qw&&S1(j-qw+1,j)==hs1[K]&&S2(j-qw+1,j)==hs2[K])++ans;
		}
		cout<<ans<<'\n'; 
	}
	return 0;
}
