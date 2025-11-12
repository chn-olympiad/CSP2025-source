#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node{
	int x1, x2, x3;
}a[N];
int ca[N];
int ton[N], top = 0;
void solve(){
	top=0;
	int n;
	scanf("%d", &n);
	for(int i = 1; i<= n; i++){
		scanf("%d%d%d", &a[i].x1, &a[i].x2, &a[i].x3);
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	long long ans = 0;
	for(int i= 1; i<= n; i++){
		if(a[i].x1 >= a[i].x2 && a[i].x1 >= a[i].x3){
			cnt1++;
			ans += a[i].x1;
			ca[i]=1;
		}else if(a[i].x2 >= a[i].x1 && a[i].x2 >= a[i].x3){
			cnt2++;
			ans += a[i].x2;
			ca[i]=2;
		}else if(a[i].x3 >= a[i].x2 && a[i].x3 >= a[i].x1){
			cnt3++;
			ca[i]=3;
			ans += a[i].x3;
		}
	}
	int yy = max(cnt1, max(cnt2, cnt3));
	if(yy<=n/2) printf("%lld\n", ans);
	else{
		if(yy == cnt1){
			for(int i = 1; i <= n; i++){
				if(ca[i]==1){
					ton[++top] = min(a[i].x1-a[i].x2, a[i].x1-a[i].x3);
				}
			}
			sort(ton+1, ton+1+top);
			for(int i = 1; i <= cnt1-(n/2); i++) ans -= ton[i];
		}else if(yy == cnt2){
			for(int i = 1; i <= n; i++){
				if(ca[i]==2){
					ton[++top] = min(a[i].x2-a[i].x1, a[i].x2-a[i].x3);
				}
			}
			sort(ton+1, ton+1+top);
			for(int i = 1; i <= cnt2-(n/2); i++) ans -= ton[i];
		}else{
			for(int i = 1; i <= n; i++){
				if(ca[i]==3){
					ton[++top] = min(a[i].x3-a[i].x1, a[i].x3-a[i].x2);
				}
			}
			sort(ton+1, ton+1+top);
			for(int i = 1; i <= cnt3-(n/2); i++) ans -= ton[i];
		}
		printf("%lld\n" ,ans);
	}
}
int main(){
	freopen("club.in","r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
	return 0;
}
