#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans;
int num[4];
struct node{
	int x,y,z;
	int maxn,maxp,maxm;
}a[500001];
int x[1000001],cnt,flag,sum;
bool cmp(node p,node q){
	if(p.maxn == q.maxn)return p.maxm < q.maxm;
	return p.maxn > q.maxn;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		num[1] = num[2] = num[3] = 0;
		ans = cnt = sum = 0;
		flag = 0;
		scanf("%lld",&n);
		for(int i = 1;i <= n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				a[i].maxn = a[i].x,a[i].maxp = 1;
				if(a[i].y >= a[i].z){
					a[i].maxm = a[i].x - a[i].y;
				}else{
					a[i].maxm = a[i].x - a[i].z;
				}
			}else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
				a[i].maxn = a[i].y,a[i].maxp = 2;
				if(a[i].x >= a[i].z){
					a[i].maxm = a[i].y - a[i].x;
				}else{
					a[i].maxm = a[i].y - a[i].z;
				}
			}else{
				a[i].maxn = a[i].z,a[i].maxp = 3;
				if(a[i].x > a[i].y){
					a[i].maxm = a[i].z-a[i].x;
				}else{
					a[i].maxm = a[i].z-a[i].y;
				}
			}
		}
		sort(a + 1,a + 1 + n,cmp);
		for(int i = 1;i <= n;i++){
			//cout<<a[i].maxn<<" "<<a[i].maxp<<" "<<a[i].maxm<<endl;
			ans += a[i].maxn;
			num[a[i].maxp]++;
			if(num[a[i].maxp] > n / 2){
				flag = a[i].maxp;
				sum = num[a[i].maxp];
			}
		}
		if(flag){
			for(int i = 1;i <= n;i++){
				if(a[i].maxp == flag)x[++cnt] = a[i].maxm;
			}
			sort(x + 1,x + 1 + cnt);
			for(int i = 1;i <= cnt - (n / 2);i++){
				ans -= x[i];
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans;
int num[4];
int dp[3][300001];
struct node{
	int x,y,z;
}a[500001];
signed main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		num[1] = num[2] = num[3] = 0;
		ans = 0;
		scanf("%lld",&n);
		for(int i = 1;i <= n;i++){
			dp[1][i] = dp[2][i] = dp[i][3] = 0;
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		}
		for(int i = 1;i <= n;i++){
			for(int j = n / 2;j >= 1;j--){
				dp[1][j] = max(dp[1][j],dp[1][j - 1] + a[i].x);
				dp[2][j] = max(dp[2][j],dp[2][j - 1] + a[i].y);
				dp[3][j] = max(dp[3][j],dp[3][j - 1] + a[i].);
			}
		}
		printf("%lld %lld %lld\n",dp[1][n / 2],dp[2][n / 2],dp[3][n / 2]);
	}
	
	return 0;
}
*/
