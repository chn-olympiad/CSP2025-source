#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 1e5+5;
int t, n , ans = 0;
bool flag = 0;
struct P{
	int s[4];
	int max1 = 0 , max2 = 0 , max3 = 0, maxc[4];
	int c = 0;
}a[mx];
bool cmp(P a ,P b){
	if(a.max1 != b.max1) return a.max1 > b.max1;
	else if(a.max2 != b.max2) return a.max2 > b.max2;
	else return a.max3 > b.max3;
}
bool cmp2(P a ,P b){
	return a.s[1] > b.s[1];
}
void dfs(int k , int now , int cnt1 , int cnt2 , int cnt3){
	if(k > n){
		ans = max(ans , now);
		return;
	} 
	for(int i = 1; i <= 3; i++){
		if(i == 1 && cnt1 < n / 2){
			cnt1++;
			now += a[k].s[i];
			k++;
			//cout << "k: " << k << " " << "now: " << now << endl;
			dfs(k , now , cnt1 , cnt2 , cnt3);
			cnt1--;
			k--;
			now -= a[k].s[i];
		}
		if(i == 2 && cnt2 < n / 2){
			cnt2++;
			now += a[k].s[i];
			k++;
			//cout << "k: " << k << " " << "now: " << now << endl;
			dfs(k , now , cnt1 , cnt2 , cnt3);
			cnt2--;
			k--;
			now -= a[k].s[i];
		}
		if(i == 3 && cnt3 < n / 2){
			cnt3++;
			now += a[k].s[i];
			k++;
			//cout << "k: " << k << " " << "now: " << now << endl;
			dfs(k , now , cnt1 , cnt2 , cnt3);
			k--;
			cnt3--;
			now -= a[k].s[i];
		}
	}
}
signed main(){

	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t--){
		int d[4] = {} ;
		stack<int> stk1 , stk2;
		cin >> n;
		if(n <= 10){
			ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= 3; j++){
					cin >> a[i].s[j];		
				}
			}
			dfs(1 , 0 , 0, 0 ,0);
			cout << ans << endl;
			continue;
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i].s[j];			
			}
			if(a[i].s[2]!=0) flag = 1;
			if(a[i].s[3]!=0) flag = 1;
		}
		if(!flag){
			sort(a + 1 , a + 1 + n , cmp2);
			for(int i = 1; i <= n / 2; i++){
				ans += a[i].s[1];
			}
			cout << ans << endl;
			continue;
		}
		else{
			for(int i = 1; i <= n; i++){
				a[i].max1 = max(max(a[i].s[1] , a[i].s[2]) , a[i].s[3]);
				a[i].max3 = min(min(a[i].s[1] , a[i].s[2]) , a[i].s[3]);
				a[i].max2 = (a[i].s[1] + a[i].s[2] + a[i].s[3]) - a[i].max1 - a[i].max3;
				
				if(a[i].max1 == a[i].max2 && a[i].max2 == a[i].max3){
					a[i].c = 1;
					a[i].maxc[1] = 1;a[i].maxc[2] = 2;a[i].maxc[3] = 3;
					continue;
				}
				if(a[i].max1 == a[i].max2){
					a[i].c = 2;
				}
				if(a[i].max1 == a[i].s[3]) a[i].maxc[1] = 3;
				if(a[i].max1 == a[i].s[2]) a[i].maxc[1] = 2;
				if(a[i].max1 == a[i].s[1]) a[i].maxc[1] = 1;
							
				if(a[i].max2 == a[i].s[1]) a[i].maxc[2] = 1;
				if(a[i].max2 == a[i].s[2]) a[i].maxc[2] = 2;
				if(a[i].max2 == a[i].s[3]) a[i].maxc[2] = 3;
				
				if(a[i].max3 == a[i].s[1]) a[i].maxc[3] = 1;
				if(a[i].max3 == a[i].s[2]) a[i].maxc[3] = 2;
				if(a[i].max3 == a[i].s[3]) a[i].maxc[3] = 3;
			}
			sort(a + 1 , a + 1 + n , cmp);
			for(int i = 1; i <= n; i++){
				if(a[i].c == 1){
					stk1.push(i);
				}
				if(a[i].c == 2){
					stk2.push(i);
				}
				if(d[a[i].maxc[1]] + 1 > n / 2){
					if(stk2.size()){
						int j = stk2.top();
						if(a[i].maxc[1] == a[j].maxc[1]){
							if(d[a[j].maxc[2]] + 1 <= n / 2){
								d[a[i].maxc[1]]--;
								d[a[j].maxc[2]]++;
								ans += a[i].max1;
							}
						}
						stk2.pop();
					}
					else if(stk1.size()){
						int j = stk1.top();
						if(a[i].maxc[1] == a[j].maxc[1]){
							if(d[a[j].maxc[2]] + 1 <= n / 2){
								d[a[i].maxc[1]]--;
								d[a[j].maxc[2]]++;
								ans += a[i].max1;
							}
							else if(d[a[j].maxc[3]] + 1 <= n / 2){
								d[a[i].maxc[1]]--;
								d[a[j].maxc[3]]++;
								ans += a[i].max1;
							}
						}
						stk1.pop();
					}
					else if(d[a[i].maxc[2]] + 1 > n / 2){
						if(d[a[i].maxc[3]] + 1> n / 2){
							continue;
						}
						else{
							ans += a[i].max3;
							d[a[i].maxc[3]]++;
						}
					}
					else{
						ans += a[i].max2;
						d[a[i].maxc[2]]++;
					}
				}	
				else{
					ans += a[i].max1;
					d[a[i].maxc[1]]++;
				}	
			}
			cout << ans <<endl;
			return;
		}
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
