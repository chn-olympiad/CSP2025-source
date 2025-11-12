#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
inline int read()
{
	int re=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while( isdigit(ch)) re=(re<<3)+(re<<1)+(ch^48),ch=getchar();
	return re*f;
}
const int N=1e5+5;
int s1[N],s2[N],s3[N];
void work()
{
	int t1=0,t2=0,t3=0;
	int n=read(),ans=0;
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read(),c=read();
		int maxn=max(max(a,b),c);
		if(a==maxn)
		{
			ans+=a;
			s1[++t1]=(a-max(b,c));
			continue;
		}
		if(b==maxn)
		{
			ans+=b;
			s2[++t2]=(b-max(a,c));
			continue;
		}
		if(c==maxn)
		{
			ans+=c;
			s3[++t3]=(c-max(b,a));
			continue;
		}
		assert(0);
	}
	sort(s1+1,s1+t1+1);
	sort(s2+1,s2+t2+1);
	sort(s3+1,s3+t3+1);
	for(int i=1;i<=t1-n/2;i++) ans-=s1[i];
	for(int i=1;i<=t2-n/2;i++) ans-=s2[i];
	for(int i=1;i<=t3-n/2;i++) ans-=s3[i];
	cout<<ans<<'\n';
}
signed main()
{
#if __MY_TEST__
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=read();
	while(t--) work();
}
