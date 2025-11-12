#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t , n , maxx;
int a[N][13] , ans[13];
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= 3 ; j++)
				cin >> a[i][j];
		for(int i = 3 ; i >= 1 ; i--)
			for(int j = 2 ; j <= n ; j++)
				if(a[j][i] > a[j - 1][i])
					for(int k = j ; k >= 2 ; k--)
						if(a[k][i] > a[k - 1][i])
						{
							swap(a[k][1] , a[k - 1][1]);
							swap(a[k][2] , a[k - 1][2]);
							swap(a[k][3] , a[k - 1][3]);
						}
		for(int j = 1 ; j <= 3 ; j++){
			int x , y , z;
			for(int i = 1 ; i <= n ; i++){
				if(j == 2 && i == 1)
				{
					ans[j] += a[i][2];
					y++;
					continue;
				}
				if(j == 3 && i == 1)
				{
					ans[j] += a[i][3];
					z++;
					continue;
				}
				if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3] && x < n / 2)
				{
					ans[j] += a[i][1];
					x++;
				}
				else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3] && y < n / 2)
				{
					ans[j] += a[i][2];
					y++;
				}	
				else if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1] && z < n / 2)
				{
					ans[j] += a[i][3];
					z++;
				}
		}
		}
		for(int i = 1 ; i <= 3 ; i++)
			maxx = max(maxx , ans[i]);
		cout << maxx << endl; 
	}
	return 0;
}
