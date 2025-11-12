#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct node{
	int a,b,c;
}a[N];
bool cmp(node a,node b){
	return a.a > b.a;
}
int n;
int diff[N];
int dp[505][505][505],ans;
bool compare(int a,int b){
	return a > b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		ans = 0;
		cin >> n;
		bool is_p = true;
		bool is = true;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			if(!(a[i].a>0&&a[i].b==0&&a[i].c==0)) is_p =false;
			if(!(a[i].a>0&&a[i].b>0&&a[i].c==0)) is = false;
		}
		if(is_p){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
		}
		else if(is){
			for(int i=1;i<=n;i++){
				ans += a[i].a;
				diff[i] = a[i].b-a[i].a;
			}
			sort(diff+1,diff+1+n,compare);
			for(int i = 1;i<=n/2;i++) ans+=diff[i];
		}
		else{
			ans = 0;
			memset(dp,0,sizeof dp);
			for(int has=1;has<=n;has++){
//				cout << endl;
//				cout << "has: " << has << endl;
				for(int i=0;i<=n/2;i++){
					for(int j=0;j<=n/2;j++){
						int t = has-j-i;
						if(t<0||t>n/2) continue;
						dp[i][j][t] = max({(t>0?dp[i][j][t-1]+a[has].c:0),
						(j>0?dp[i][j-1][t]+a[has].b:0),
						(i>0?dp[i-1][j][t]+a[has].a:0)});
						ans = max(ans,dp[i][j][t]);
//						cout << i << " " << j << " " << t << endl;
//						cout << dp[i][j][t] << "======" << endl;
					}
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
