#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x1,x2,x3;
}a[100010];
bool cmp(node x,node y){
	long long i1 = x.x1,j1 = x.x2,k1 = x.x3;
	long long i2 = y.x1,j2 = y.x2,k2 = y.x3;
	long long c1 = max(max(i1,j1),k1);
	long long c2 = max(max(i2,j2),k2);
	return c1 > c2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while (t--){
		long long n,flag = 1,flag1 = 1;
		cin>>n;
		for (long long i = 1;i <= n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
			if (a[i].x2 != 0 || a[i].x3 != 0){
				flag = 0;
			}
			if (a[i].x3 != 0){
				flag1 = 0;
			}
		}
		sort(a+1,a+1+n,cmp);
		int ans = 0;
		if (flag){
			for (int i = 1;i <= n/2;i++){
				ans += a[i].x1;
			}
			cout<<ans<<endl;
			continue;
		}
		if (n == 2){
			cout<<max(max(max(max(a[1].x2+a[2].x1,a[1].x3+a[2].x1),a[1].x1),max(max(a[1].x1+a[2].x3,a[1].x2+a[2].x3),a[1].x3)),max(max(a[1].x1+a[2].x2,a[1].x3+a[2].x2),a[1].x2))<<endl;
			continue;
		}
		if (flag1){
			int x = n/2,y = n/2;
			for (long long i = 1;i <= n/2;i++){
				long long m = max(a[i].x1,a[i].x2);
				ans += m;
				if (a[i].x1 == m){
					x--;
				}else{
					y--;
				}
			}
			for (long long i = n/2+1;i <= n;i++){
				if (x > 0 && y > 0){
					long long m = max(a[i].x1,a[i].x2);
					ans += m;
					if (a[i].x1 == m){
						x--;
					}else{
						y--;
					}
				}
				else if (x > 0){
					ans += a[i].x1;
				}
				else if (y > 0){
					ans += a[i].x2;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		int x = n/2,y = n/2,z = n/2;
		for (long long i = 1;i <= n/2;i++){
			long long m = max(max(a[i].x1,a[i].x2),a[i].x3);
			ans += m;
			if (a[i].x1 == m){
				x--;
			}else if (a[i].x2 == m){
				y--;
			}else{
				z--;
			}
		}
		for (long long i = n/2+1;i <= n;i++){
			if (x > 0 && y > 0 && z > 0){
				long long m = max(max(a[i].x1,a[i].x2),a[i].x3);
				ans += m;
				if (a[i].x1 == m){
					x--;
				}else if (a[i].x2 == m){
					y--;
				}else{
					z--;
				}
			}
			else if (x > 0 && y > 0){
				long long m = max(a[i].x1,a[i].x2);
				ans += m;
				if (a[x].x1 == m){
					x--;
				}else{
					y--;
				}
			}
			else if (x > 0 && z > 0){
				long long m = max(a[i].x1,a[i].x3);
				ans += m;
				if (a[x].x1 == m){
					x--;
				}else{
					z--;
				}
			}
			else if (y > 0 && z > 0){
				long long m = max(a[i].x2,a[i].x3);
				ans += m;
				if (a[x].x2 == m){
					y--;
				}else{
					z--;
				}
			}
			else if (x > 0){
				ans += a[i].x1;
			}
			else if (y > 0){
				ans += a[i].x2;
			}
			else if (z > 0){
				ans += a[i].x3;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
		/*
		for (long long i = 1;i <= n;i++){
			if (x <= n/2){
				dp[i][1] = max(max(dp[i-1][2]+a[i].x1,dp[i-1][3]+a[i].x1),dp[i-1][1]);
				x++;
			}
			else{
				dp[i][1] = dp[i-1][1];
			}
			if (y <= n/2){
				dp[i][2] = max(max(dp[i-1][1]+a[i].x2,dp[i-1][3]+a[i].x2),dp[i-1][2]);
				y++;
			}
			else{
				dp[i][2] = dp[i-1][2];
			}
			if (z <= n/2){
				dp[i][3] = max(max(dp[i-1][1]+a[i].x3,dp[i-1][2]+a[i].x3),dp[i-1][3]);
				z++;
			}	
			else{
				dp[i][3] = dp[i-1][3];
			}
		}
		*/
