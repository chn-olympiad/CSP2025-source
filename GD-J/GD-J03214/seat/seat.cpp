#include<bits/stdc++.h>
using namespace std;
struct s{
	int num,b;
}a[105];
int c[15][15];
bool cmp(s a,s b)
{
	return a.b>b.b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].b);
		a[i].num=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int l=1,i=1,r=1,ansx=0,ansy=0;
	while(i<=n*m)
	{
		if(a[i].num==1)
		{
			ansx=l,ansy=r;
			break;
		}
		c[l][r]=a[i].b;
		i++;
		if(l%2==1)
		{
			r++;
			if(r>n)
			{
				r=n;
				l++;
			}
		}
		else
		{
			r--;
			if(r<1)
			{
				r=1;
				l++;
			}
		}
	}
	printf("%d %d",ansx,ansy);
}
