#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
struct p{
	int h;
	int l;
	int bh;
	int sum;
}a[1000];
bool cmp(p x1,p x2)
{
	return x1.sum>x2.sum;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		a[i].bh=i;
		cin>>a[i].sum;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				a[cnt].h=j;
				a[cnt].l=i;	
			}
		}
		else{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				a[cnt].h=j;
				a[cnt].l=i;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].bh==1)
		{
			cout<<a[i].l<<" "<<a[i].h;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
