#include <bits/stdc++.h>
#define int long long
using namespace std;
int t , n , ai[100000] , aj[100000] , az[100000] , cnt1 , cnt2 , cnt3 , panduan = 1; 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
    	int a[n][3];
    	for(int i= 0;i < n;i++)
    	{
    		cin >> ai[i];
			cin >> aj[i];
			cin >> az[i];
			if(aj[i] != az[i] || aj[i] != 0)
			{
				panduan = 0;
			}
		}
		if(panduan == 1)
    	{
		    sort(ai,ai+n);
	        int cnt = 0;
	        for(int i = n-1;i >= n/2-1;i--)
    	    {
		        cnt += ai[i];
	        }
	        cout << cnt;
	        return 0;
	    }
    }
	return 0;
}
