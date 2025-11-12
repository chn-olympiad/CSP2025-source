#include <bits/stdc++.h>
using namespace std;
int n,m,score[105],c,r;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> score[i];
	}
	int a = score[1];
	sort(score,score+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		if(score[i] == a)
		{
			c = i / n;
			if(c%2 == 1)
			{
				r = i % n;
				if(r == 0)
				{
					r = n;
				}
			}
			else
			{
				r = n-i%n+1;
			}
			break;
		}
	}
	cout << c+1 << " " << r%n;
	return 0;
}
