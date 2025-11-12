#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x>y;
}
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int fi=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int h=1, l=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==fi)
		{
			cout << l << " " << h;
			break;
		}
		if(l%2==1)
		{
			if(h==n)
			{
				l++;
			}
			else
			{
				h++;
			}
		}
		else
		{
			if(h==1)
			{
				l++;
			}
			else
			{
				h--;
			}
		}
	}
	return 0;
}


