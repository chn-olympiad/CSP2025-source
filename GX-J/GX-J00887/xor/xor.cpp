#include<bits/stdc++.h>
using namespace std;
int n,m;
int s=0,b=1;
int a[100010];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int x;
	int g=n*m;
	cin >> x;
	for(int i=1; i<=g; i++)
		cin >> a[i];
	sort(a+1,a+g+1);
	for(int i=g; i>=1; i--)
	{
		s++;
		if(a[i]>=x)
		{
			if(s>n)
			{
				b++;
				for(int j=i; j>=1; j--)
				{
					s--;
					if(a[j]>=x)
					{
						if(s<1)
						{   
							b++;
							s=1;
							break;
						}
					}
				}
			}
		}
		if(s>n)
		{
			b++;
			s--;
		}
		if(s<1)
		{
			b++;
			s++;
		}
		if(a[i]<x)
		{
			cout << b << " " << s;
			return 0;
		}
	}
}

