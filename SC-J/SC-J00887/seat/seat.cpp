#include <bits/stdc++.h>
using namespace std;

struct stu
{
	int score,loc;
}a[150];
bool cmp(stu s,stu x)
{
	return s.score>x.score;
}
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i].score;
		a[i].loc=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i].loc==1)
		{
			cout<<int(ceil(i*1.0/n))<<" ";
			if (int(ceil(i*1.0/n))%2==1)
			{
				if (i%n!=0)
				{
					cout<<i%n;
				}
				else
				{
					cout<<n;
				}
			}
			else
			{
				cout<<n+1-i%n;
			}
			break;
		}
	}
	return 0;
 } 