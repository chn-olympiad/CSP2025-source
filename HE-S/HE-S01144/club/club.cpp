#include <bits/stdc++.h>
using namespace std;
const int _ = 100010;
int cun, k, t, ban, n, a[_][3], cnt[3], cha[_][3];
long long ans;
struct hhh{
	int a;
	inline bool operator <(const hhh & x)const{
		return a > x. a;
	}
}x;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
scanf("%d", & t);
while(t --){
	priority_queue<hhh> q;
	while(q. size()){
		q. pop();
	}
	scanf("%d", & n);
	cnt[0] = cnt[1] = cnt[2] = ans = 0;
	ban = (n >> 1);
	for(int i = 1; i <= n; i ++){
		scanf("%d%d%d", & a[i][0], & a[i][1], & a[i][2]);
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
			cnt[0] ++;
			ans += a[i][0];
			cha[i][0]= - 1, cha[i][1] = a[i][0] - a[i][1], cha[i][2] = a[i][0] - a[i][2];
		}
		else if(a[i][1] >= a[i][2] && a[i][1] >= a[i][0]){
			cnt[1] ++;
			ans += a[i][1];
			cha[i][0]= a[i][1] - a[i][0], cha[i][1] = - 1, cha[i][2] = a[i][1] - a[i][2];
		}
		else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][0]){
			cnt[2] ++;
			ans += a[i][2];
			cha[i][0]= a[i][2] - a[i][0], cha[i][1] = a[i][2] - a[i][1], cha[i][2] = - 1;
		}
	}
	if(cnt[0] <= ban && cnt[1] <= ban && cnt[2] <= ban){
//		cout<<"TEW";
		printf("%lld\n", ans);
		continue;
	}
	if(cnt[0] > ban){
		for(int i = 1; i <= n; i ++){
			if(cha[i][0] == - 1){
				q. push((hhh){min(cha[i][1], cha[i][2])});
			}
		}
		for(int i = cnt[0]; i > ban; i --){
			x = q. top();
			q. pop();
			ans -= x. a;
		}
	}
	else if(cnt[1] > ban){
		for(int i = 1; i <= n; i ++){
			if(cha[i][1] == - 1){
				q. push((hhh){min(cha[i][0], cha[i][2])});
			}
		}
		for(int i = cnt[1]; i > ban; i --){
			x = q. top();
			q. pop();
			ans -= x. a;
		}
	}
	else if(cnt[2] > ban){
		for(int i = 1; i <= n; i ++){
			if(cha[i][2] == - 1){
				q. push((hhh){min(cha[i][0], cha[i][1])});
			}
		}
		for(int i = cnt[2]; i > ban; i --){
			x = q. top();
			q. pop();
			ans -= x. a;
		}
	}
	printf("%lld\n", ans);
}
	return 0;
}
