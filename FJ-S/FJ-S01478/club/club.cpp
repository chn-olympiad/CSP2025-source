#include<bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e5 + 5;

int T,n;
ll can[N],now[4];
struct node{
	int num,gap;
}tt[N];

int cmp(node x,node y){
	return x.gap < y.gap;
} 

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ll ans = 0;
		now[1] = now[2] = now[3] = 0;
		for(int i = 1; i <= n; i++)
			can[i] = 0;
		for(int i = 1; i <= n; i++){
			int a,b,c;
			cin >> a >> b >> c;
			tt[i].num = i;
			if(a >= b && b >= c) can[i] = 1,now[1]++,ans += a,tt[i].gap = a - b;
			else if(a >= c && c >= b) can[i] = 1,now[1]++,ans += a,tt[i].gap = a - c;
			else if(b >= a && a >= c) can[i] = 2,now[2]++,ans += b,tt[i].gap = b - a;
			else if(b >= c && c >= a) can[i] = 2,now[2]++,ans += b,tt[i].gap = b - c;
			else if(c >= a && a >= b) can[i] = 3,now[3]++,ans += c,tt[i].gap = c - a;
			else if(c >= b && b >= a) can[i] = 3,now[3]++,ans += c,tt[i].gap = c - b;
		}
		int change = 0,sh = 0;
		sort(tt + 1,tt + 1 + n, cmp);
		if(now[1] <= (n / 2) && now[2] <= (n / 2) && now[3] <= (n / 2)) {
			cout << ans << "\n";
			continue;
		}
		if(now[1] > (n / 2)) change = 1,sh = now[1] - (n / 2);
		if(now[2] > (n / 2)) change = 2,sh = now[2] - (n / 2);
		if(now[3] > (n / 2)) change = 3,sh = now[3] - (n / 2);
		for(int i = 1,j = 0; i <= n; i++){
			if(can[tt[i].num] == change){
				ans -= tt[i].gap,j++;
			}
			if(j == sh)break;
		}
		cout << ans << "\n";
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
