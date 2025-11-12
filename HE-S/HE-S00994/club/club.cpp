#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct cl{
	int x;
	int y;
	int z;
}a[100005];
bool cmp(cl a_, cl b){
	if(a_.x!=b.x) return a_.x>b.x;
	if(a_.y!=b.y) return a_.y>b.y;
	return 0;
}
int T, n;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		long long ans=0;
		int n_1=0, n_2=0;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a+1, a+n+1, cmp);
		for(int i=1;i<=n;i++){
			if(a[i].x>a[i].y&&n_1<n/2){
				ans += a[i].x;
				n_1++;
			}
			else if(n_2<n/2){
				ans += a[i].y;
				n_2++;
			}
			else if(n_1<n/2){
				ans += a[i].x;
				n_1++;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
