#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,w[100000],t = 1,v = 1,y = 0,ans = 0,num = 0;
    cin >> n >> m;
    bool u = false,o = true;
    for(int i = 1;i <= n * m;i++)
    {
		cin >> w[i];
	}
	for(int i = 2;i <= n * m;i++)
	{
		if(w[1] > w[i])
		{
			ans++;
		}
	}
	num = n * m - ans;
	if(t == 1 && v != 1)
	{
		u = true;
	}
	for(int i = 1;i <= num - 1;i++)
	{
		if(t == n || u == true)
		{
			v++;
			y++;
            o = false;
			if(v > m)
			{
				v--;
			} 
		}
		if(t <= n && t >= 1)
		{ 
		    if(o != false)
		    {
		        if(y % 2 == 0)
                {
				    t++;
			    }
			    if(y % 2 == 1)
			    {
				    t--;
			    }
			}
		}
		o = true;
	}
	cout << v << " " << t;
}
