#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef double llf;
//----------------------
int n,k,a[500050],sum[500050],len=0;
struct part
{
	int l,r;
}p[500050];
bool cmp(part x,part y)
{
	if(x.r!=y.r)return x.r<y.r;
	else return x.l<y.l;
}
bool v[500050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int j=i;j<=n;++j)
		{
			if((i==j&&a[i]==k)||(sum[j]^sum[i-1])==k)
			{
				p[++len].l=i;
				p[len].r=j;
				break;
			}
		}
	}
	
	sort(p+1,p+len+1,cmp);
	int cnt=0;
	int last=0;
	for(int i=1;i<=len;++i)
	{
//		if(p[i].l<=p[i+1].l&&p[i+1].r<=p[i].r)
//		{
//			continue;
//		}
		if(p[last].r<p[i].l)
		{
			++cnt;
			last=i;
			v[i]=1;
		}
	}
	
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

2 1 0 3

0 0 1 0 
0 0 0 1
0 0 0 0 
0 0 1 1




dp[i][k]=max(dp[i-1][k],dp[i-1][k^a[i]])

LQH保佑我~zr保佑我~ 




----
     --------
       --
          --
          
          

*/ 
