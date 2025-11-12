#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=0,h=0,f=0;
	for(int i=1;i<=n*m;i++)
	{
		if(f==1) h--;
		else h++;
		if(i%n==1) l++;
		if(h>n||(h<1&&f==1))
		{
			if(l%2==0)
			{
				h=n;
				f=1;
			}
			else
			{
				h=1;
				f=0;
			}
		}
		if(a[i]==t)
		{
			cout<<l<<' '<<h;
			return 0;
		}
	}
	return 0;
}
