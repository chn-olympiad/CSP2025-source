#include<bits/stdc++.h>
using namespace std;

int n, m, s, c, CCF;
int a[555];

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+2, a+1+n*m, cmp);
	
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]<a[1])
		{
			s = i-1;
			while(s>n)
			{
				c++;
				s -= n;
			}
			if((c+1)%2==0)
			{
				CCF = n-s+1;
			}else
			{
				CCF = s;
			}
			cout<<c+1<<" "<<CCF;
			return 0;
		}
	}
	
	return 0;
}
