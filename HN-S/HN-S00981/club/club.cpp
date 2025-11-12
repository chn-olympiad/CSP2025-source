#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T, n, ans;
struct Node{
	int d1,d2,d3,chose;
}a[N];
int cnt[5], cnt1[N], cnt2[N], cnt3[N];
bool cmp1(Node x, Node y){
	return x.d1 > y.d1;
}
bool cmp2(Node x, Node y){
	return x.d2 > y.d2;
}
bool cmp3(Node x, Node y){
	return x.d3 > y.d3;
} 
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){	
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d1 >= a[i].d2 && a[i].d1 >= a[i].d3){
				a[i].chose = 1;
			}else if(a[i].d2 >= a[i].d1 && a[i].d2 >= a[i].d3){
				a[i].chose = 2;
			}else if(a[i].d3 >= a[i].d1 && a[i].d3 >= a[i].d2){
				a[i].chose = 3;
			}
		}
		for(int i = 1; i <= n; i++){
			cnt[a[i].chose]++;
		}
		sort(a + 1,a + 1 + n, cmp1);
		sort(a + 1,a + 1 + n, cmp2);
		sort(a + 1,a + 1 + n, cmp3);
		for(int k = 1; k <= n; k++){
				if(a[k].d2 == 0 && a[k].d3 == 0){
					for(int s = 1; s <= (n / 2) ;s++){
						ans += a[k].d1;
					}
				cout << ans << '\n';
				continue;
			}
		}
		for(int i = 1; i <= 3; i++){
			if(cnt[i] > (n/2)){
				for(int j = 1; j <= cnt[i]; j++){
					if(i == 1){
						if((a[cnt[i]].d2 + a[cnt[i]].d3) > a[cnt[i+1]].d2+ a[cnt[i+1]].d3){
							cnt[i]--;
							if(a[i].d2 > a[i].d3){
								a[i].chose = 2;
							}else{
								a[i].chose = 3;
							}
						}
					}else if(i == 2){
						if((a[cnt[i]].d1 + a[cnt[i]].d3) > a[cnt[i+1]].d1+ a[cnt[i+1]].d3){
							cnt[i]--;
							if(a[i].d1 > a[i].d3){
								a[i].chose = 1;
							}else{
								a[i].chose = 3;
							}
						}
					}else if(i == 3){
						if((a[cnt[i]].d2 + a[cnt[i]].d1) > a[cnt[i+1]].d2+ a[cnt[i+1]].d1){
							cnt[i]--;
							if(a[i].d2 > a[i].d1){
								a[i].chose = 2;
							}else{
								a[i].chose = 1;
							}
						}
					}
				}
				
			}
		}
		for(int i = 1; i <= n; i++){
			if(a[i].chose == 1){
				ans += a[i].d1;
			}else if(a[i].chose == 2){
				ans += a[i].d2;
			}else if(a[i].chose == 3){
				ans += a[i].d3;
			}
		}
	cout << ans << '\n';
	ans = 0;
	}
	return 0;
}


