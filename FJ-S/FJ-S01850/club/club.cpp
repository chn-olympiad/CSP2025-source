#include<bits/stdc++.h>
using namespace std;
int t;
struct N{
	long long x,y,z;
}a[100005];
bool cmp(N p,N q){
	if(p.x == q.x && p.y == q.y) return p.z > q.z;
	if(p.x == q.x) return p.y > q.y;
	return p.x > q.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		long long n;
		cin >> n;
		long long f = 0,b = 0,c = 0,s = 0;
		int k = n/2;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;	
		}
		if(n == 2){
			cout << max(a[1].x+a[2].y,max(a[1].x+a[2].z,max(a[1].y+a[2].x,max(a[1].y+a[2].z,max(a[1].z+a[2].x,a[1].z+a[2].y))))) << endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i <= n;i++){
			int g = max(a[i].x,max(a[i].y,a[i].z));
			if(g == a[i].x && f < k){
				++f;
				s += g;
			}else if(g == a[i].y && b < k){
				++b;
				s += g;
			}else if(g == a[i].z && c < k){
				++c;
				s += g;
			}
		}
		cout << s << endl;
	}
	return 0;
} 
