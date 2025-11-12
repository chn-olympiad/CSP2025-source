#include<bits/stdc++.h>
using namespace std;
int t,n,maxx=-1,dp[100005][5],sum[1000005][5][5],last[5];//sum表示第i个人在使用k时所使用过的j的数量
bool flag[500005];
struct node {
	int x,id,total;
} a[100005][5];
int c[100005][5];
struct Node {
	int total,idx;
} b[100005];
bool cmp(Node a,Node b) {
	return a.total>b.total;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		memset(c,0,sizeof(c));
		memset(last,0,sizeof(last));
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		memset(flag,0,sizeof(flag));
		maxx=-1;
		cin>>n;
		a[0][1].id=1;
		a[0][2].id=2;
		a[0][3].id=3;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			a[i][1].id=1;
			a[i][2].id=2;
			a[i][3].id=3;
			b[i].total=max({a[i][1].x,a[i][2].x,a[i][3].x});
			b[i].idx=i;
		}
		sort(b+1,b+n+1,cmp);
//		for(int i=1; i<=n; i++) {
//			cout<<b[i].idx<<" ";
//		}
//		cout<<'\n';
		for(int i=1;i<=n;i++){
			c[i][1]=a[b[i].idx][1].x;
			c[i][2]=a[b[i].idx][2].x;
			c[i][3]=a[b[i].idx][3].x;
		}
		for(int i=1;i<=n;i++){
			a[i][1].x=c[i][1];
			a[i][2].x=c[i][2];
			a[i][3].x=c[i][3];
		}
//		for(int i=1; i<=n; i++) {
//			if(flag[i]==0&&flag[b[i].idx]==0) {
//				swap(a[i][1],a[b[i].idx][1]);
//				swap(a[i][2],a[b[i].idx][2]);
//				swap(a[i][3],a[b[i].idx][3]);
//				flag[i]=1;
//				flag[b[i].idx]=1;
//				cout<<i<<" "<<b[i].idx<<'\n';
//			}
//		}
//		return 0;
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=3; j++) {
//				cout<<a[i][j].x<<" ";
//			}
//			cout<<'\n';
//		}
        last[1]=1;
        last[2]=2;
        last[3]=3;
		dp[1][1]=a[1][1].x;
		dp[1][2]=a[1][2].x;
		dp[1][3]=a[1][3].x;
		sum[1][1][1]++;
		sum[1][2][2]++;
		sum[1][3][3]++;
		for(int i=2; i<=n; i++) {
//			sort(a[i]+1,a[i]+4,cmp);
			for(int j=1; j<=3; j++) {
				for(int k=1; k<=3; k++) {
					if(sum[i-1][j][k]+1<=n/2) {
						if(dp[i-1][k]+a[i][j].x>dp[i][j]) {
							dp[i][j]=dp[i-1][k]+a[i][j].x;
//							cout<<dp[i-1][k]<<" "<<a[i][j].x<<'\n';
							sum[i][k][j]=sum[i-1][k][j]+1;
						}
					}else{
						sum[i][k][j]=sum[i-1][k][j];
					}
				}
//				sum[i][j]=sum[i-1][j]+1;
//				cout<<"("<<i<<","<<j<<"):"<<dp[i][j]<<" "<<sum[i][j][2]<<'\n';
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				for(int k=1;k<=3;k++){
//					cout<<sum[i][j][k]<<" ";
//				}
//			}
//			cout<<'\n';
//		}
//        cout<<sum[4][2][2]<<'\n';
		int ans=-1;
		for(int i=1; i<=3; i++) {
			ans=max(ans,dp[n][i]);
//			cout<<a[i][1].id<<" ";
		}
		cout<<ans<<'\n';
	}
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
3 1 0
0 3 0 
0 2 0
2
10 9 8
4 6 0
*/
