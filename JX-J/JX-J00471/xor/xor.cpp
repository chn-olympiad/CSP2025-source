#include<bits/stdc++.h>
using namespace std;
struct node
{
	int e,f;
}ans[500010];
int n,k,o,p,t,z,u,cnt;
int a[500010],qz[500010],w[25];
int q[500010][25];
bool cmp(node x,node y)
{
	if(x.f != y.f)return x.f < y.f;
	return x.e < y.e;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		t=a[i];
		for(int j=22;j>=1;j--)
		{
			o=t%2;
			t/=2;
			q[i][j]=o;
			if(i>=2)
			{
				if(q[i][j]==q[i-1][j])q[i][j]=0;
				else q[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=22;j>=1;j--)
		{
			qz[i]+=pow(2,22-j)*q[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			z=0;
			for(int l=22;l>=1;l--)//get i to j xor sum
			{
				if(q[j][l]==q[i-1][l])w[l]=0;
				else w[l]=1;
				z+=pow(2,22-l)*w[l];
			}
			if(z==k)
			{
				ans[++u].e=i;
				ans[u].f=j;
				break;
			}
		}
	}
	sort(ans+1,ans+1+u,cmp);
	node sc;
	sc.e=ans[1].e;sc.f=ans[1].f;
	for(int i=2;i<=u;i++)
	{
		if(ans[i].e>sc.f)
		{
			cnt++;
			sc.e=ans[i].e;sc.f=ans[i].f;
		}
	}
	cout<<cnt+1;
	return 0;
}
/*
101111000011010

001001010101100//unknown

100110010110110

//same
*/
