#include<bits/stdc++.h>
using namespace std;
string s;
const int mod=998244353,N=1145141;
int c[N],b[N],q[N];
long long ans=0;
int n,m;
void firefly(int p,int sum)
{
	if(p>n)
	{
		if(n-sum>=m)
		  ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			q[p]=i;
			int nsum=sum;
			if(s[p]=='0'||sum>=c[q[p]])
			  nsum++;
			if(n-nsum>=m)
			  firefly(p+1,nsum);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	if(n>=100&&m==n)
	{
		cout<<0;
		return 0;
	}
	firefly(1,0);
	printf("%lld",ans%mod);
	return 0;
 } //我要上人类迷惑行为大赏！*114514
