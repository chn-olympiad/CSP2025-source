#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N];
int s[N],p[N][3],an,ans=INT_MIN;
void solve(int y,int ma)
{
	ans=max(ma,ans);
	for(int i=y;i<=an;i++)
	{
		for(int j=i+1;j<=an;j++)
		{
			if(p[i][2]<p[j][1])
			{
				ma++;
				solve(j,ma);
				ma--;
			}
		}
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)s[i]=a[i];
		else if(i>=2)s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				if(a[i]==k)
				{
					an++;
					p[an][1]=i;
					p[an][2]=j;
				}
				continue;
			}
			if(i==1)
			{
				if(s[j]==k)
				{
				an++;
				p[an][1]=1;
				p[an][2]=j;
				}
				continue;
			}
			int t=s[j]^s[i-1];
			if(t==k)
			{
				an++;
				p[an][1]=i;
				p[an][2]=j;
			}
		}
	}
	for(int i=1;i<=an;i++)solve(i,1);
	cout<<ans;
}
