#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int T,n,ans,c[4],mx;
struct P{
	int a[4],mx,md,mn;
}p[N];

bool cmp1(P a,P b){
	return a.a[a.mx] > b.a[b.mx];
}

bool cmp2(P a,P b){
	if(a.mx == mx && b.mx != mx) return 1;
	if(a.mx != mx && b.mx == mx) return 0;
	return a.a[mx] - a.a[a.md] < b.a[mx] - b.a[b.md]; 
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		c[1] = c[2] = c[3] = ans = 0;
		for(int i = 1,a,b,c;i <= n;i++){
			cin >> a >> b >> c;
			if(a > b){
				if(a > c){
					if(b > c) p[i] = {{0,a,b,c},1,2,3};
					else p[i] = {{0,a,b,c},1,3,2};
				}
				else p[i] = {{0,a,b,c},3,1,2};
			}
			else{
				if(b > c){
					if(a > c) p[i] = {{0,a,b,c},2,1,3};
					else p[i] = {{0,a,b,c},2,3,1};
				}
				else p[i] = {{0,a,b,c},3,2,1};
			}
		}
		sort(p + 1,p + 1 + n,cmp1);
		for(int i = 1;i <= n;i++){
			++c[p[i].mx];
			ans += p[i].a[p[i].mx];
		}
		if(c[1] <= n / 2 && c[2] <= n / 2 && c[3] <= n / 2){
			cout << ans << '\n';
			continue;
		}
		if(c[1] > n / 2) mx = 1;
		if(c[2] > n / 2) mx = 2;
		if(c[3] > n / 2) mx = 3;
		sort(p + 1,p + 1 + n,cmp2);
		for(int i = 1;i <= n;i++){
			ans += p[i].a[p[i].md] - p[i].a[mx];
			if(--c[mx] <= n / 2) break;
		}
		cout << ans << '\n';
	}
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
