#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T, n, dp[114514][5], cnt[114514][5], maxn;
struct node{
	int d[5];
}a[114514];
bool fl1=true, fl2=true;
bool cmp(node x, node y){
	int sx=0, sy=0;
	for(int i=1;i<=3;i++){
		sx+=x.d[i];
		sy+=y.d[i];
	}
	if(sx!=sy)return sx>sy;
	for(int i=1;i<=3;i++){
		if(x.d[i]!=y.d[i]){
			return x.d[i]>y.d[i];
		}
	}
}
bool ccf(node x, node y){
	return x.d[1]>y.d[1];
}
bool noi(node x, node y){
	if(abs(x.d[1]-x.d[2])!=abs(y.d[1]=y.d[2]))return abs(x.d[1]-x.d[2])>abs(y.d[1]=y.d[2]);
	return max(x.d[1], x.d[2])>max(y.d[1], y.d[2]);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		memset(dp, 0, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		maxn=-114;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i].d[j];
				if(a[i].d[2]!=0 || a[i].d[3]!=0){
					fl1=false;
				}
				if(a[i].d[3]!=0){
					fl2=false;
				}
			}
		}
		if(fl1){
			maxn=0;
			sort(a+1, a+n+1, ccf);
			for(int i=1;i<=n/2;i++){
				maxn+=a[i].d[1];
			}
			cout << maxn << '\n';
			return 0;
		}
		if(fl2){
			maxn=0;
			int xa=0, xb=0;
			sort(a+1, a+n+1, noi);
			for(int i=1;i<=n;i++){
				if(xa==n/2)maxn+=a[i].d[2];
				else if(xb==n/2)maxn+=a[i].d[1];
				else if(a[i].d[1]>a[i].d[2]){
					maxn+=a[i].d[1];
					xa++;
				}else{
					maxn+=a[i].d[2];
					xb++;
				}
			}
			cout << maxn << '\n';
		}
		sort(a+1, a+n+1, cmp);
		for(int i=1;i<=n;i++){
//			cout << '\n';
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					if(cnt[i-1][j]<n/2){
						dp[i][k]=max(dp[i][k], dp[i-1][j]+a[i].d[k]);
					}
					maxn=max(maxn, dp[i][k]);
				}
			}
//			for(int k=1;k<=3;k++)cout << dp[i][k] << "  ";
//			cout << "  " << maxn;
			for(int j=1;j<=3;j++){
				if(dp[i][j]==maxn){
					cnt[i][j]=cnt[i-1][j]+1;
				}else{
					cnt[i][j]=cnt[i-1][j];
				}
			}
//			cout << "   ";
//			for(int k=1;k<=3;k++)cout << cnt[i][k] << ' ';
		}
		cout << maxn << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
3 5 1
5 3 4
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
