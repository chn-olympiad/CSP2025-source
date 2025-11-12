#include<bits/stdc++.h>
using namespace std;
int n, m, s, anst, o;
int a[105],b[15][15];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
    cin >> n >> m;
    s = n * m;
    for (int i = 0 ; i < s ; i ++)
    {
    	cin >> a[i];
	}
	anst = a[0];
	sort(a + 0, a + s, cmp);
	for (int i = 0 ; i < m ; i ++)
    {
    	if (i % 2 == 0)
    	{
    		for (int j = 0 ; j < n ; j ++)
            {
        	    b[j][i] = a[o];
    	        o ++;
	        }
		}
    	if (i % 2 != 0)
    	{
    		for (int j = n - 1 ; j >= 0 ; j --)
            {
        	    b[j][i] = a[o];
    	        o ++;
	        }
		}
	}
	for (int i = 0 ; i < n ; i ++)
    {
    	for (int j = 0 ; j < m ; j ++)
        {
        	if (anst == b[i][j]) cout << j + 1 << " " << i + 1;
	    }
	}
	return 0;
}
