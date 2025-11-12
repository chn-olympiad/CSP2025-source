#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][4],b[N]; 
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
		int n,p;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = 2;j <= 3;j++)
			{
				    if(a[i][j] != 0) p = 1;
			}
		}
		if(!pd)
		{
			for(int i = 1;i <= n;i++)
			{
				b[i] = a[i][1];
			}
			sort(b+1,b + 1 + n);
			for(int i = n;i > n/2;i--) ans += b[i];
		}
		cout << ans << '\n';
	}
    return 0;
}
