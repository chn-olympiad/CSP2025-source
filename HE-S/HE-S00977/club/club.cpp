#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t;
int n,f[N][3];
struct node{int x,y,z;bool f;}a[N];
bool fA,fA1,fA2;
bool cmpA(node a,node b){return a.x > b.x;}
bool cmpA1(node a,node b){return a.y > b.y;}
bool cmpA2(node a,node b){return a.z > b.z;}
int sumx,sumy,sumz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin >> t;
	while(t--){
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0 || a[i].z != 0) fA = 1;
			if(a[i].x != 0 || a[i].z != 0) fA1 = 1;
			if(a[i].y != 0 || a[i].x != 0) fA2 = 1;
			sumx += a[i].x;
			sumy += a[i].y;
			sumz += a[i].z;
		}
		if(fA == 0){
			sort(a + 1,a + n + 1,cmpA);
			for(int i = 1; i <= n / 2; i++) ans += a[i].x;
			cout << ans << "\n";
		}
		else if(fA1 == 0){
			sort(a + 1,a + n + 1,cmpA1);
			for(int i = 1; i <= n / 2; i++) ans += a[i].y;
			cout << ans << "\n";
		}
		else if(fA2 == 0){
			sort(a + 1,a + n + 1,cmpA2);
			for(int i = 1; i <= n / 2; i++) ans += a[i].z;
			cout << ans << "\n";
		}
		else{
			if(sumx > sumy && sumy > sumz){
				sort(a + 1,a + n + 1,cmpA);
				for(int i = 1; i <= n / 2; i++){
					ans += a[i].x;
					a[i].f = 1;
				}
				sort(a + 1,a + n + 1,cmpA1);
				int h = 0;
				for(int i = 1; i <= n; i++){
					if(a[i].f == 1) continue;
					if(h == n / 2) break;
					ans += a[i].y;
					h++;
				}
			}
			else if(sumx > sumz && sumz > sumy){
				sort(a + 1,a + n + 1,cmpA);
				for(int i = 1; i <= n / 2; i++){
					ans += a[i].x;
					a[i].f = 1;
				}
				sort(a + 1,a + n + 1,cmpA2);
				int h = 0;
				for(int i = 1; i <= n; i++){
					if(a[i].f == 1) continue;
					if(h == n / 2) break;
					ans += a[i].z;
					h++;
				}
			}
			
			
			if(sumy > sumx && sumx > sumz){
				sort(a + 1,a + n + 1,cmpA1);
				for(int i = 1; i <= n / 2; i++){
					ans += a[i].y;
					a[i].f = 1;
				}
				sort(a + 1,a + n + 1,cmpA);
				int h = 0;
				for(int i = 1; i <= n; i++){
					if(a[i].f == 1) continue;
					if(h == n / 2) break;
					ans += a[i].x;
					h++;
				}
			}
			else if(sumy > sumz && sumz > sumx){
				sort(a + 1,a + n + 1,cmpA1);
				for(int i = 1; i <= n / 2; i++){
					ans += a[i].y;
					a[i].f = 1;
				}
				sort(a + 1,a + n + 1,cmpA2);
				int h = 0;
				for(int i = 1; i <= n; i++){
					if(a[i].f == 1) continue;
					if(h == n / 2) break;
					ans += a[i].z;
					h++;
				}
			}
			
			if(sumz > sumy && sumy > sumx){
				sort(a + 1,a + n + 1,cmpA2);
				for(int i = 1; i <= n / 2; i++){
					ans += a[i].z;
					a[i].f = 1;
				}
				sort(a + 1,a + n + 1,cmpA1);
				int h = 0;
				for(int i = 1; i <= n; i++){
					if(a[i].f == 1) continue;
					if(h == n / 2) break;
					ans += a[i].y;
					h++;
				}
			}
			else if(sumz > sumx && sumx > sumy){
				sort(a + 1,a + n + 1,cmpA2);
				for(int i = 1; i <= n / 2; i++){
					ans += a[i].z;
					a[i].f = 1;
				}
				sort(a + 1,a + n + 1,cmpA);
				int h = 0;
				for(int i = 1; i <= n; i++){
					if(a[i].f == 1) continue;
					if(h == n / 2) break;
					ans += a[i].x;
					h++;
				}
			}
		} 
		cout << ans << "\n";
	}
	return 0;
} 
