#include <bits/stdc++.h>
using namespace std;
int a,s,z,d=0,c=1,e=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>s;
	int w[a*s],ww[a][s];
	cin>>z;
	w[0]=z;
	for (int i=1;i<=s*a;i++)
	{
		cin>>w[i];
		
	}
	e=a*s;
	sort(w,w+a*s);
	for (int i=1;i<=s;i++)
	{
		for (int j=1;j<=a;)
		{
			if (w[e]==z)
			{
				if (i%2==0)
				{
					
					cout<<i<<" "<<a-j%a;
					return 0;
				}
				else
				{
					cout<<i<<" "<<j%a;
					return 0;
				}
			}	
			if (i%2==0)
			{
				j++;
			}
			else
			{
				j--;
			}
			e--;
		}
	}
	return 0;
}
