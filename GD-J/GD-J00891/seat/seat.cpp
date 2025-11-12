#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,lie = 1,hang = 1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r = a[1];
	sort(a+1,a+n*m+1);
	for (int id = n * m;id>=1;id--)
	{
		if (a[id] == r) 
		{
			cout<<lie<<' '<<hang<<endl;
			return 0;
		}
		if (lie % 2) 
		{
			hang ++;
			if (hang > n)
			{
				lie ++;
				hang --;
			}
		}
		else
		{
			hang --;
			if (hang < 1)
			{
				lie ++;
				hang ++;
			}
		}
	}
	return 0;
}
