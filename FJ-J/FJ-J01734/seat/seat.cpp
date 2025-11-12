#include<bits/stdc++.h>
using namespace std;
int a[110], n, m, x, h = 1, l, k;
bool f;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++)
	{
		cin>>a[i];
	}
	x = a[1];
	k = n * m;
	sort(a + 1,a + n*m +1);
	for(int i = 1;i <= m;i++)
	{
		l++; 
		for(int j = 1;j <= n;j++)
		{
			if(j!=1)
			{
				if(f) 
				h--;
			else 
				h++;
			}
			if(a[k]==x)
			{
				cout<<l<<" "<<h<<endl;
				return 0;
			}
			k--;
		}
		if(f) f = 0;
		else f = 1;
	}
	return 0;
}

