#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int a[n];
    int mx = 0,s = 0;
    for(int i = 0;i < n; ++ i)
    {
    	cin >> a[i];
    	if(a[i] > mx)
    	 mx = a[i];
    	s += a[i];
	}
	if(n < 3)
	 cout << 0;
	else if(n == 3)
	{
		if(s > mx * 2)
		 cout << 1;
		else
		 cout << 0;
	}
	return 0;
}
