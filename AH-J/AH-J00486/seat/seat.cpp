#include<bits/stdc++.h>
using namespace std;
long long n,m,s,cnt;
struct strta
{
	long long id,mark;
}a[10010];
bool cmp(strta a,strta b)
{
	return a.mark > b.mark;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i = 1; i <= n * m; i++)
	{
		cin>>a[i].mark;
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i].id == 1)
		{
			s = i;
			break;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1; j <= m; j++)
			{
				cnt++;
				if(cnt == s)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j = m; j >= 1; j--)
			{
				cnt++;
				if(cnt == s)
				{
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
