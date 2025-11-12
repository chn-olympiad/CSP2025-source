#include <bits/stdc++.h>
using namespace std;
//燃尽了 
inline int read(){
	int cnt = 0, f = 1;
	char h = getchar();
	while(h < '0' || h > '9'){
		if(h == '-')f = -f;
		h = getchar();
	}
	while(h >= '0' && h <= '9'){
		cnt = (cnt << 3) + (cnt << 1) + (h ^ 48);
		h = getchar();
	}
	return cnt * f;
}

inline void write(int x){
	if(x < 0){
		putchar('-');
	}
	if(x > 9){
		write(x / 10);
	}
	putchar(x % 10 + '0');
}

const int N = 1e5 + 100, INF = 1e9;
int t, n, ans;
int nn;
struct node{
	int w1, w2, w3, c;
};
node a[N];

bool cmp(node i, node j){
	return i.w1 > j.w1;
}

bool cp(node i, node j){
	return i.c > j.c;
}

void dfs(int w, int c1, int c2, int c3, int i){
	if(c1 > nn || c2 > nn || c3 > nn)return;
	if(i == n + 1){
		ans = max(ans, w);
		return;
	}
	int ii = i + 1;
	dfs(w + a[i].w1, c1 + 1, c2, c3, ii);
	dfs(w + a[i].w2, c1, c2 + 1, c3, ii);
	dfs(w + a[i].w3, c1, c2, c3 + 1, ii);
}

void solve(){
	n = read();
	nn = n / 2;
	memset(a, 0, sizeof(a));
	ans = 0;
	int j2 = 0, j3 = 0;
	for(int i = 1; i <= n; i++){
		a[i].w1 = read(); a[i].w2 = read(); a[i].w3 = read();
		if(a[i].w2 != 0)j2 = 1;
		if(a[i].w3 != 0)j3 = 1;
	}
	if(n <= 10){//20分 
		dfs(0, 0, 0, 0, 1);
	}
	else if(j2 == 0 && j3 == 0){//5分 
		sort(a + 1, a + 1 + n, cmp);
		for(int i = 1; i <= nn; i++){
			ans += a[i].w1;
		}
	}
	else if(j3 == 0){//15分 
		for(int i = 1; i <= n; i++){
			a[i].c = a[i].w1 - a[i].w2;
		}
		sort(a + 1, a + 1 + n, cp);
		for(int i = 1; i <= nn; i++){
			ans += a[i].w1;
		}
		for(int i = nn + 1; i <= n; i++){
			ans += a[i].w2;
		} 
	}
	else{//未知 
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		priority_queue <int, vector <int>, greater <int> > q1, q2, q3;
		for(int i = 1; i <= n; i++){
			if(a[i].w1 > a[i].w2 && a[i].w1 > a[i].w3){
				q2.push(a[i].w1 - a[i].w2);
				q3.push(a[i].w1 - a[i].w3);
				cnt1++;
				ans += a[i].w1;
				if(cnt1 > nn){
					cnt1--;
					int ww2 = q2.top();
					int ww3 = q3.top();
					if(ww2 < ww3 && cnt2 < nn){
						ans -= ww2;q2.pop();
						cnt2++;
					}
					else{
						ans -= ww3;q3.pop();
						cnt3++;
					}
				}
			}
			else if(a[i].w2 > a[i].w1 && a[i].w2 > a[i].w3){
				q1.push(a[i].w2 - a[i].w1);
				q3.push(a[i].w2 - a[i].w3);
				cnt2++;
				ans += a[i].w2;
				if(cnt2 > nn){
					cnt2--;
					int ww1 = q1.top();
					int ww3 = q3.top();
					if(ww1 < ww3 && cnt1 < nn){
						ans -= ww1;q1.pop();
						cnt1++;
					}
					else{
						ans -= ww3;q3.pop();
						cnt3++;
					}
				}
			}
			else if(a[i].w3 > a[i].w2 && a[i].w3 > a[i].w1){
				q2.push(a[i].w3 - a[i].w2);
				q1.push(a[i].w3 - a[i].w1);
				cnt3++;
				ans += a[i].w3;
				if(cnt3 > nn){
					cnt3--;
					int ww1 = q1.top();
					int ww2 = q2.top();
					if(ww1 < ww2 && cnt1 < nn){
						ans -= ww1;q1.pop();
					}
					else{
						ans -= ww2;q2.pop();
					}
				}
			}
			else if(a[i].w1 == a[i].w2){
				if(a[i].w2 == a[i].w3){
					ans += a[i].w1;
				}
				else{
					q3.push(a[i].w1 - a[i].w3);
					ans += a[i].w1;
					cnt3--;
					nn--;
				}
			}
			else if(a[i].w2 == a[i].w3){
				q1.push(a[i].w2 - a[i].w1);
				ans += a[i].w2;
				cnt1--;
				nn--;
			}
			else if(a[i].w1 == a[i].w3){
				q2.push(a[i].w1 - a[i].w3);
				ans += a[i].w1;
				cnt3--;
				nn--;
			}
		}
	} 
	write(ans);putchar('\n');
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	priority_queue <int> q;
	t = read();
	while(t--){
		solve();
	}
	return 0;
}
/*
            ﹏﹏﹏ 
          ╭  ┊┊  ╮
        ╭╯        ╰╮
        │  ﹋  ﹋    │   
        │╰  ╰╯  ╯│
	    ╰            ╯ 	  
    	 ╰  ﹋﹋    ╯  
    ╭╯╭╯  FO祖   ╰╮╰╮
  ╭╯╭╯    ⌒⌒｜｜ ╰╮╰╮
  │  │    ╱││╲｜ ｜│  │      
  │  │  .╱ ╯╰ ╲ ｜ │  │
  │  │   │ ││ │｜  │  │  
  │  │  ╱  ││  ╲   │  │          
  │  ╰─             ─╯  │
  ╰▁▁▁▁  ╯ ╰ ▁▁▁▁ ╯   
  
  
             ︵︵
          ╭       ╮
        ╭╯       ╰╮
        │ ﹋   ﹋   │   
        │           │  
    	 ╰         ╯  
    ╭╯╭╯        ╰╮╰╮
  ╭╯╭╯            ╰╮╰╮
  │  │      ╱╲      │  │      
  │  │                │  │
  │  │  │ ╯  ╰ │  │  │            
  │  ╰─╯ │  │ ╰─╯  │
  ╰▁▁▁▁       ▁▁▁▁ ╯ 
*/
