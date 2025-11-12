#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int n = 0,s = 0,a[105],y = 0,b[15][15],k = 0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>s;
	for(int i = 0;i < n*s;i++)
	{
		cin>>a[i];
	}
	y = a[0];
	sort(a+0,a+(n*s),cmp);
	int j = 1;
	bool h = 0;
	int f = 0;
	for(int i = 0;i < n;k++)
	{
		if(a[k] == y)
		{
			cout<<i+1<<" "<<j+f;
			return 0;
		}
		if(j == s)
		{
			i++;
			h = 1;
			f++;
		}
		else if(j == 0 && i != 0)
		{
			i++;
			h = 0;
			f--;
		}
		if(h)
		{
			j--;
		}
		else
		{
			j++; 
		}
		
	}
	return 0;
}
