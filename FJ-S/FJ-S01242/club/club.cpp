#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t , n , vis[4];
struct Node{
	int x , y , z;
}a[N];
bool cmp(Node p , Node q){
	if(p.x > q.x) return true;
	else if(p.x == q.x && p.y > q.y) return true;
	else return false;
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%d" , &t);
	while(t--){
		int ans = 0;
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++) a[i].x = a[i].y = a[i].z = 0;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d%d%d" , &a[i].x , &a[i].y , &a[i].z);
		}
		sort(a + 1 , a + n + 1 , cmp); 
//		for(int i = 1 ; i <= n ; i++){
//			cout << a[i].x << " " << a[i].y << " " << a[i].z << endl; 
//		}
		for(int i = 1 ; i <= 4 ; i++) vis[i] = n / 2;
		for(int i = 1 ; i <= n ; i++){	
			if(a[i].x > a[i].y){
				if(vis[1] != 0){
					ans += a[i].x;
					vis[1]--;	
				}  
				else if(vis[2] != 0){
					ans += a[i].y;
					vis[2]--;
				}
			}
			else{
				if(vis[2] != 0){
					ans += a[i].y;
					vis[2]--;
				}
				else if(vis[1] != 0){
					ans += a[i].x;
					vis[1]--;
				}
			}
//			cout << ans << endl;
		}
		printf("%d\n" , ans);
	}
	
	return 0;
} 
