#include <bits/stdc++.h>
using namespace std;

int T , n;
struct node{int x1 , x2 , x3 , f;}p[100010];
bool c1(node x , node y){return x.x1 - max(x.x2 , x.x3) > y.x1 - max(y.x2 , y.x3);}
bool c2(node x , node y){return x.x2 - x.x3 > y.x2 - y.x3;}
bool c3(node x , node y){return x.x3 > y.x3;}

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int cnt[4] = {} , sum = 0 , v[4] = {};
		for(int i = 1 ; i <= n ; i++)
			cin >> p[i].x1 >> p[i].x2 >> p[i].x3 , p[i].f = 0;
		sort(p + 1 , p + n + 1 , c1);
		for(int i = 1 ; i <= n ; i++){
			if(cnt[1] >= n / 2){v[1] = 1; break;}
			if(p[i].x1 >= p[i].x2 && p[i].x1 >= p[i].x3)
				cnt[1]++ , sum += p[i].x1 , p[i].f = 1; 
		}sort(p + 1 , p + n + 1 , c2);
		for(int i = 1 ; i <= n ; i++){
			if(cnt[2] >= n / 2){v[2] = 1; break;}
			if(p[i].f) continue;
			if(p[i].x2 >= p[i].x3)
				cnt[2]++ , sum += p[i].x2 , p[i].f = 1; 
		}sort(p + 1 , p + n + 1 , c3);
		for(int i = 1 ; i <= n ; i++){
			if(cnt[3] >= n / 2){v[3] = 1; break;}
			if(p[i].f) continue;
			cnt[3]++ , sum += p[i].x3 , p[i].f = 1; 
		}for(int i = 1 ; i <= n ; i++){
			if(!p[i].f){
				if(v[1]) sum += max(p[i].x2 , p[i].x3);
				else if(v[2]) sum += max(p[i].x1 , p[i].x3);
				else if(v[3]) sum += max(p[i].x1 , p[i].x2);
			}
		}cout << sum << endl;
	}return 0;
}
 
