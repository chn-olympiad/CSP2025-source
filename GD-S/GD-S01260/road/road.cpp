#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5 , M = 15 , K = 1e4 + 5;
int n , m , k; 
struct node{
	int u , v , w , id;
}a[N] , g[N];
int b[M] , c[K];
int mark[K];
bool cmp(node x , node y){
	return x.w + x.id < y.w + y.id;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		a[i].id = 0;
	}
	int cnt = 1;
	for(int i = 1 ; i <= k ; i++){
		cin >> b[i];
		for(int j = 1 ; j <= n ; j++){
			cin >> c[j];
			g[m + i * j].u = n + i , g[m + i * j].v = j , g[m + i * j].w = c[j];		
		}
		for(int j = 1 ; j <= n ; j++){
			for(int k = j + 1 ; k <= n ; k++){
				a[m + cnt].u = j , a[m + cnt].v = k , a[m + cnt].w = g[m + i * j].w + g[m + i * k].w , a[m + cnt].id = b[i]; 
				cnt++;
			}
		}
	}
//	for(int i = 1 ; i <= m + cnt ; i++) cout << a[i].u << " " << a[i].v << " " << a[i].w << "\n";
	sort(a + 1 , a + m + cnt + 1 , cmp);
//	for(int i = 1 ; i <= m + cnt ; i++) cout << a[i].u << " " << a[i].v << " " << a[i].w << "\n";
	int f = 0 , cost = 0;
	for(int i = 1 ; i <= m + cnt ; i++){
		if(f == n) break;
		if((mark[a[i].u] == 0 || mark[a[i].v] == 0) && a[i].id == 0){
			f += !(mark[a[i].u]);
			f += !(mark[a[i].v]);
			mark[a[i].u] = 1 , mark[a[i].v] = 1;
			cost += a[i].w;
		}
	}
	int minn = cost;
	for(int i = 1 ; i <= k ; i++){
		memset(mark , 0 , sizeof(mark));
		for(int o = i ; o <= k ; o++){
			int tf = 0 , tcost = 0;
			bool flag = 0;
			bool ff = 0;
			for(int j = 1 ; j <= m + cnt ; j++){
				if(tf == n){
					ff = 1;
					break;
				}
				if((mark[a[j].u] == 0 || mark[a[j].v] == 0)){
					tf += !(mark[a[j].u]);
					tf += !(mark[a[j].v]);
					mark[a[j].u] = 1 , mark[a[j].v] = 1;
					tcost += a[j].w;
					for(int l = i ; l <= o ; l++){
						if(a[j].id == b[l] && flag == 0){
							flag = 1;
							tcost += b[i];
						}						
					}

				}
			}
			if(ff) minn = min(minn , tcost);			
		}
	}
	cout << minn;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
