#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],p,h=1,l=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			p=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(p>1&&l%2==1)
			{
				h++;
//				p--;
			}
			else if(p>1&&l%2==0)
			{
				h--;
//				p--;
			}
			else
			{
				cout<<l<<" "<<h;
				return 0;
			}
			p--;
		}
		l++;
	}
	return 0;
}
