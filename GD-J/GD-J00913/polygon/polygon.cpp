#include<bits/stdc++.h>
using namespace std;
const int N = 5010,modd = 998244353;
long long a[N],sum[N][N];
int n;
long long maxn[N][N];
long long nemaxn[N][N];
long long ans;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	memset(maxn,-1,sizeof(maxn));
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
		for(int j = 1; j <= i; j++){
			sum[j][i] = sum[j][i - 1] + a[i];
			maxn[j][i] = max(maxn[j][i - 1],a[i]);
			sort(a + j,a + j + i);
			nemaxn[j][i] = a[i + j - 2];
			printf("%lld %lld\n",nemaxn[j][i],maxn[j][i]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			//int maxx = findmax(j,i);
			if(((sum[j][i] - sum[i][i]) > maxn[j][i]) && (abs(i - j) >= 3) || ((sum[j][i] - sum[j][j]) > maxn[j][i]) && (abs(i - j) >= 3)){
				ans++;
				ans %= modd;
			}
			if((sum[j][i] > maxn[j][i]) && (abs(i - j) >= 3)){
				ans++;
				ans %= modd;
			}
		}
	}
	printf("%lld",ans % modd);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
