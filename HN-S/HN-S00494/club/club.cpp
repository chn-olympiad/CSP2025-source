#include<bits/stdc++.h>
#define MN 100000
using namespace std;
int t,n,total,sum,ans,one,two,three,one1,two2,three3,vis[MN],sp,sl;
struct node{
	int sum,num,id;
}a[MN];
bool cmp(node x,node y){
	return x.sum > y.sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n;
		total = 0,ans = 0,sp = 0,one1 = 0,two2 = 0,three3 = 0;
		vector < int > g(3 * n + 1);
		int cnt = 0;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= 3;j++){
				cin >> a[++cnt].sum;
				a[cnt].num = j;
				a[cnt].id = i;
			}
			bool flag1 = (a[cnt].sum == a[cnt - 1].sum);
			bool flag2 = (a[cnt - 2].sum == a[cnt - 1].sum);
			if (flag1 && flag2){
				ans += a[cnt].sum;
				one++,sp++;
			}else if (flag1 || flag2){
				if (a[cnt].sum > a[cnt - 2].sum){
					ans += a[cnt].sum;
					one++;
					if (flag1){
						sp++;
					}
				}else {
					ans += a[cnt - 2].sum;
					three++;
					if (flag2){
						sp++;
					}
				}
			}else {
				vector<int>ve;
				if (a[cnt].sum != 0){
					ve.push_back(a[cnt].sum);
				}
				if (a[cnt - 1].sum != 0){
					ve.push_back(a[cnt - 1].sum);
				}
				if (a[cnt - 2].sum != 0){
					ve.push_back(a[cnt - 2].sum);
				}
				sort(ve.begin(),ve.end());
				if (ve[ve.size() - 1] == a[cnt - 1].sum){
					ans += a[cnt - 1].sum;
					two++;
				}else if (ve[ve.size() - 1] == a[cnt - 2].sum){
					ans += a[cnt - 2].sum;
					three++;
				}else {
					ans += a[cnt].sum;
					one++;
				}
			}
			vis[i] = 0;
		}
		if (max(0,three - n / 2) + max(0,two - n / 2) + max(0,one - n / 2) <= sp){
			cout << ans << "\n";
			continue;
		}
		cnt = 0,total = 0,ans = 0,sp = 0,sl = 0,one1 = 0,two2 = 0,three3 = 0,one = 0,two = 0,three = 0;
		sort(a + 1,a + 3 * n + 1,cmp);
		for (int i = 1;i <= 3 * n;i++){
			if (total == n) break;
			if (vis[a[i].id] == 1) continue;
			if (a[i + 1].sum != a[i].sum){
				ans += a[i].sum;
				vis[a[i].id] = 1;
			}else {
				sl = 0;
				if (vis[i] == 0){
					if (a[i].num == 1){
						if (one1 < n / 2){
							one1++;
							total++;
							one = a[i].sum;
							ans += a[i].sum;
						}else {
							if (a[i].sum == one){
								sp++;
								vis[a[i].id] = 2;
							}
						}
					}else if (a[i].num == 2){
						if (two2 < n / 2){
							two2++;
							total++;
							two = a[i].sum;
							ans += a[i].sum;
						}else {
							if (a[i].sum == two){
								sp++;
								vis[a[i].id] = 2;
							}
						}
					}else {
						if (three3 < n / 2){
							three3++;
							total++;
							three = a[i].sum;
							ans += a[i].sum;
						}else {
							if (a[i].sum == three){
								sp++;
								vis[a[i].id] = 2;
							}
						}
					}
				}else if (vis[i] == 2){
					sl++;
					if (sp > 0){
						sp--;
						if (a[i].num == 1){
							one1++;
						}else if (two2 < n / 2){
							two2++;
						}else {
							three3++;
						}
						total++;
						vis[a[i].id] = 1;
						ans += a[i].sum;
					}
				}else {
					continue;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
