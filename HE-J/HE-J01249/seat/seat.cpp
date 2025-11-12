#include <bits/stdc++.h>
using namespace std;

int n , m;
struct node{int f , h;}p[110];
bool cmp(node x , node y){return x.f > y.f;}

int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n * m ; i++) cin >> p[i].f , p[i].h = i;
	sort(p + 1 , p + n * m + 1 , cmp);
	for(int i = 1 ; i <= m ; i++){
		if(i % 2){
			for(int j = 1 ; j <= n ; j++)
				if(p[(i - 1) * n + j].h == 1){
					cout << i << " " << j;
					return 0;
				}
		}else{
			for(int j = n ; j >= 1 ; j--)
				if(p[(i - 1) * n + n - j + 1].h == 1){
					cout << i << " " << j;
					return 0;
				}
		}
	}
	return 0;
}

