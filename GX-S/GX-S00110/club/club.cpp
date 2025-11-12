#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 20;
int t;

struct man{
	int a;
	int b;
	int c;
} g[MAXN];

int judge(man k){ //judge the max choise
    int x = k.a, y = k.b, z = k.c;
    int ans = max(x, y);
    ans = max(ans, z);
    if(x == ans) return 1;
    else if (y == ans) return 2;
    else if (z == ans) return 3;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	cin >> t;
	g[100019].a = g[100019].b = g[100019].c = 99812;
	while (t--){
		int n;
		int a[MAXN], b[MAXN], c[MAXN];
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> g[i].a >> g[i].b >> g[i].c;
        int x=0, y=0, z=0;
		for (int i = 1; i <= n; i++){
			if(judge(g[i]) == 1){
                x += 1;
				a[x] = i;
			}else if (judge(g[i]) == 2){
			    y += 1;
				b[y] = i;
			}else{
			    z += 1;
				c[z] = i;
			}
		}

		int mid = n >> 1 ,ans = 0;
		if (x <= mid && y <= mid && z <= mid){
            for (int i = 1; i <= x; i++)
                ans += g[a[i]].a;
            for (int i = 1; i <= y; i++)
                ans += g[b[i]].b;
            for (int i = 1; i <= z; i++)
                ans += g[c[i]].c;
            cout << ans <<endl;
            continue;

		}
		int nx = x, ny = y, nz = z;
		while (x > mid){
            int minn = 1000009, pas;
            for (int i = 1; i <= x; i++){
                minn = min(minn, g[a[i]].a);
                if (minn == g[a[i]].a) pas = i;
            }
            if (g[a[pas]].b > g[a[pas]].c && y < mid){
                y++, x--;
                b[y] = pas;
            }else if(g[a[pas]].b >g[a[pas]].c && y >= mid){
                z++, x--;
                c[z] = pas;
            }else if(g[a[pas]].b < g[a[pas]].c && z < mid){
                z++, x--;
                c[z] = pas;
            }else if(g[a[pas]].b < g[a[pas]].c && z >= mid){
                y++, x--;
                b[y] = pas;
            }else if(g[a[pas]].b == g[a[pas]].c && y < mid){
                y++, x--;
                b[y] = pas;
            }else if(g[a[pas]].b == g[a[pas]].c && z < mid){
                z++, x--;
                c[z] = pas;
            }
            a[pas] = 100019;
		}
		while (y > mid){
            int minn = 1000009, pas;
            for (int i = 1; i <= y; i++){
                minn = min(minn, g[b[i]].b);
                if (minn == g[b[i]].b) pas = i;
            }
            if (g[b[pas]].a > g[b[pas]].c && x < mid){
                x++, y--;
                a[x] = b[pas];
            }else if(g[b[pas]].a >g[b[pas]].c && x >= mid){
                z++, y--;
                c[z] = b[pas];
            }else if(g[b[pas]].a < g[b[pas]].c && z < mid){
                z++, y--;
                c[z] = b[pas];
            }else if(g[b[pas]].a < g[b[pas]].c && z >= mid){
                x++, y--;
                a[x] = b[pas];
            }else if(g[b[pas]].a == g[b[pas]].c &&x < mid){
                x++, y--;
                a[x] = b[pas];
            }else if(g[b[pas]].a == g[b[pas]].c &&x >= mid){
                z++, y--;
                c[z] = b[pas];
            }
            b[pas] = 100019;
		}
		while (z > mid){
            int minn = 1000009, pas;
            for (int i = 1; i <= z; i++){
                minn = min(minn, g[c[i]].c);
                if (minn == g[c[i]].c) pas = i;
            }
            if (g[c[pas]].a > g[c[pas]].b && x < mid){
                x++, z--;
                a[x] = c[pas];
            }else if(g[c[pas]].a >g[c[pas]].b && x >= mid){
                y++, z--;
                b[z] = c[pas];
            }else if(g[c[pas]].a < g[c[pas]].b && y < mid){
                y++, z--;
                b[z] = c[pas];
            }else if(g[c[pas]].a < g[c[pas]].b && y >= mid){
                x++, z--;
                a[x] = c[pas];
            }else if(g[c[pas]].a == g[c[pas]].c &&x < mid){
                x++, y--;
                a[x] = c[pas];
            }else if(g[c[pas]].a == g[c[pas]].c &&x >= mid){
                z++, y--;
                b[z] = c[pas];
            }
            c[pas] = 100019;
		}

        for (int i = 1; i <= nx && x != 0; i++)
            if(g[a[i]].a!=99812)ans += g[a[i]].a;
        for (int i = 1; i <= ny && y != 0; i++)
            if(g[b[i]].b!=99812)ans += g[b[i]].b;
        for (int i = 1; i <= nz && z != 0; i++)
            if(g[c[i]].c!=99812)ans += g[c[i]].c;
        cout << ans << endl;
		}
	return 0;
}
