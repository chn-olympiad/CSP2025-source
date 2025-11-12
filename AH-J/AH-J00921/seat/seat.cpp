#include <bits/stdc++.h>
using namespace std;
int n,m;
int zy;
int a[105];
bool cmp(int q,int p)
{
	return q>p;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) zy=a[i];
	}
	int nn=m*n;
	int s;
	sort(a+1,a+nn+1,cmp);
	for(int i=1;i<=nn;i++)
	{
		if(a[i]==zy) 
		{
			s=i;
			break;
		}
	}
	if(s<=n) cout<<1<<' '<<s;
	else
	{
		cout<<(s+1)/n<<' ';
		if(((s+1)/n)%2==0)
		{
			int h=s%n-1;
			cout<<n-h;
		}
		else
		{
			cout<<s%n;
		}
	}
	return 0;
}
