#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50005];
int ans=0;
struct lr
{
	int l,r,x;
};
lr p[100005];
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p[(i-1)*n+j].l=i,p[(i-1)*n+j].r=j;
			int xo=a[i];
			for(int k=i;k<=j;k++)
			{
				xo=xo|(!a[k]);
			}
			p[(i-1)*n+j].x=xo;
		}
	}
	int rr=0;
	bool flag=0;
	for(int i=1;i<=n*(n+1)/2;i++)
	{
		if(flag==1)
		{
		    if(p[i].l<=rr)
			{
				continue;
            }
			else
			{
				if(p[i].x==k)
				{
					ans++;
					flag=1;
					rr=p[i].r;
				}
				else
				{
					flag=0;
				}
			}
		}
		if(p[i].x==k)
		{
			ans++;
			flag=1;
			rr=p[i].r;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
