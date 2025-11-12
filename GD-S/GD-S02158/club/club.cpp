#include <bits/stdc++.h>
using namespace std;
int t,n,max1 = -1,max2 = -1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1; i <= t;i++){
		cin >> n;
		int team[4][n + 1],teamren[n + 1];
		for(int e = 1;e < t;e++){
			for(int j = 1;j <= n;j++){
				cin >> team[e][j];
				if(e = 2) max1 = max(team[e][j],max1);
				if(e = 3) max2 = max(team[e][j],max2);
				}
			}
		for(int j = 1;j <= n;j++) teamren[j] = 1;
		if(n == 2){
			int ans = 0;
			ans = max(ans,team[1][2] + team[2][1]);
			ans = max(ans,team[1][2] + team[3][1]);
			ans = max(ans,team[2][2] + team[3][1]);
			ans = max(ans,team[2][2] + team[1][1]);
			ans = max(ans,team[3][2] + team[2][1]);
			ans = max(ans,team[3][2] + team[1][1]);
			cout << ans;
		}
		else if(max1 == max2 && max1 == 0)
		{
			long long ans = 0;
			sort(team[1] + 1,team[1] + n + 1);
			for(int j = n;j > n / 2;j--){
				ans += team[1][j];
			}
			cout << ans;
		}
		else if(max2 == 0){
			int a[n + 1],b[n + 1],c[n + 1],x = 0,y = 0,z = 0,sum1,sum2,sum3;
			for(int j = 1;j <= n;j++){
				a[j] = 0;
				b[j] = 0;
				c[j] = 0;
			}
			for(int j = 1;j <= n;j++){
				if(team[1][j] > team[2][j]){
					a[j] = team[1][j];
					sum1 += team[1][j];
					x++;
				}
				else if(team[1][j] == team[2][j]){
					b[j] = team[1][j];
					sum2 += team[1][j];
					y++;
				}
				else{
					c[j] = team[2][j];
					sum3 += team[2][j];
					z++;
				}
			}
			if(x > n / 2){
				for(int e = 1;e <= (x - (n / 2));e++){
					int minn = -1,minx;
					for(int j = 1;j <= n;j++){
						if(a[j] == 0) continue;
						if(minn == a[j]){
							if(team[2][minx] > team[2][j]){
								minn = a[j];
								minx = j;
							}
						}
						if(minn > a[j]){
							minn = a[j];
							minx = j;
						}
					}
					sum1 -= a[minx];
					sum3 += team[2][minx];
					a[minx] = 0;
					c[minx] = team[2][minx];
					x--;
					y++;
				}
			}
			else if (y > n / 2){
				for(int e = 1;e <= (z - (n / 2));e++){
					int minn = -1,minx;
					for(int j = 1;j <= n;j++){
						if(c[j] == 0) continue;
						if(minn == c[j]){
							if(team[1][minx] > team[1][j]){
								minn = c[j];
								minx = j;
							}
						}
						if(minn > c[j]){
							minn = c[j];
							minx = j;
						}
					}
					sum3 -= c[minx];
					sum1 += team[1][minx];
					c[minx] = 0;
					a[minx] = team[1][minx];
					x++;
					y--;
				}
			}
			cout << sum1 + sum2 + sum3;
		}
		else{
			for(int j = 1;j < 4;j++){
				sort(team[j] + 1,team[j] + 1 + n);
			}
			long long max1 = 0,max2 = 0,max3 = 0;
			for(int j = n;j >= (n / 2);j++){
				max1 += team[1][j];
				max2 += team[2][j];
				max3 += team[3][j];
			}
			if((max1 > max2 && max2 > max3) || (max2 > max1 && max1 > max3)){
				cout << max1 + max2;
			}
			else if((max3 > max1 && max1 > max2) || (max1 > max3 && max3 > max2)){
				cout << max1 + max3;
			}
			else{
				cout << max2 + max3;
			}
		}
	}
}
