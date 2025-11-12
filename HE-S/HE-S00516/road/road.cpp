#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct f{
	int u;
	int v;
	int w;
}a[1000100];
struct ff{
	int l;
	int r;
	int x;
}kk[20];
int cmp(f x, f y){
	if(x.w != y.w){
		return x.w < y.w;
	}else if(x.w == y.w){
		return x.u < y.u;
	}
}
int t[11000][11000], sum = 0;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	int js = 0;
	for(int i = 1; i <= k; i++){
		int x;
		cin >> x;
		kk[i].l = m + js + 1;
		kk[i].r = m + js + n;
		kk[i].x = x;
		for(int j = 1; j <= n; j++){
			js++;
			a[m + js].u = n + i;
			a[m + js].v = j;
			cin >> a[m + js].w;
			a[m + js].w += x;
			
		}
	}
	n += k;
	m += js;
//	cout << m <<endl;
	for(int i = 1; i <= n; i++){
		t[i][i] = 1;
	}
	sort(a + 1, a + 1 + m, cmp);
//	for(int i = 1; i <= m; i++){
//		cout << a[i].w << " ";
//	}
//	cout <<endl;
	for(int i = 0; i <= n; i++){
		t[i][i] = 1;
	}
	
	for(int i = 1; i <= m; i++){
		if(t[a[i].u][a[i].v] == 0){
//			cout << "U" << a[i].u << " V " << a[i].v <<endl;
//			cout << a[i].u << " " << a[i].v << " w << " << a[i].w <<endl;
			sum += a[i].w;
			t[a[i].u][a[i].v] = 1;
			t[a[i].v][a[i].u] = 1;
//			for(int j = 1; j <= n; j++){
//				for(int k = 1; k <= n; k++){
//					cout << t[j][k] << " ";
//				}
//				cout <<endl;
//			}
//			cout << endl;
			for(int j = 0; j <= n; j++){
				if(t[a[i].u][j] == 1){
					t[a[i].v][j] = 1;
					t[j][a[i].v] = 1;
				}
				if(t[a[i].v][j] == 1){
					t[a[i].u][j] = 1;
					t[j][a[i].u] = 1;
				}
			}
//			for(int j = 1; j <= n; j++){
//				for(int k = 1; k <= n; k++){
//					cout << t[j][k] << " ";
//				}
//				cout <<endl;
//			}
//			cout <<endl;
		}
		for(int j = 1; j <= n; j++){
			if(t[a[i].u][j] == 0){
//				cout << "break" <<endl;
				break;
			}
			if(i == n){
				cout << sum;
//				cout << "sum" <<endl;
				return 0;
			}
		}
		
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
