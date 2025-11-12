#include<bits/stdc++.h>
using namespace std;
//#define int long long
struct point{
	int x,y,z;
}a[100005];
int d[100005],b[100005];
int n,ans = 0;
const int m = 3;
void dfs(int cur,int cnta,int cntb,int cntc,int sum){
	if(cur == n + 1){
		ans = max(ans,sum);
		return;
	}
	if(cnta + 1 <= n / 2) dfs(cur+1,cnta+1,cntb,cntc,sum+a[cur].x);
	if(cntb + 1 <= n / 2) dfs(cur+1,cnta,cntb+1,cntc,sum+a[cur].y);
	if(cntc + 1 <= n / 2) dfs(cur+1,cnta,cntb,cntc+1,sum+a[cur].z);
}
bool cmp1(point a,point b){
	return a.x > b.x;
}
bool cmp2(point a,point b){
	return a.y > b.y;
}
bool cmp3(point a,point b){
	return a.z > b.z;
}
void count(int x,int y,int z,int or1,int or2,int or3){
	int sum = 0;
	for(int i = 1;i <= x;i++){
		sum = sum + (or1 == 1 ? a[i].x : (or1 == 2 ? a[i].y : a[i].z));
	}
	for(int i = x + 1;i <= x + y;i++){
		sum = sum + (or1 == 1 ? a[i].x : (or2 == 2 ? a[i].y : a[i].z));
	}
	for(int i = x + y + 1;i <= x + y + z;i++){
		sum = sum + (or1 == 1 ? a[i].x : (or3 == 2 ? a[i].y : a[i].z));
	}
	ans = max(ans,sum);
}
void work(){
	cin >> n;
	bool b0 = true,c0 = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if(a[i].y) b0 = false;
		if(a[i].z) c0 = false;
	}
	if(b0 && c0){
		for(int i = 1;i <= n;i++){
			d[i] = a[i].x;
		}
		sort(d+1,d+1+n);
		int ans = 0;
		for(int i = n;i > n / 2;i--){
			ans = ans + d[i];
		}
		cout << ans;
	}
	else if(n <= 10){
		ans = 0;
		dfs(1,0,0,0,0);
		cout << ans;
	}
	else{
		ans = 0;
		for(int i = 0;i <= n / 2;i++){
			for(int j = 0;j + i <= n;j++){
				int k = n - i - j;
				if(k > n / 2) continue;
				if(j > n / 2) continue;
				if(max(max(i,j),k) == i){
					sort(a+1,a+1+n,cmp1);
					if(max(j,k) == j){
						sort(a+i+1,a+1+n,cmp2);
						count(i,j,k,1,2,3);
					}
					if(max(j,k) == k){
						sort(a+i+1,a+1+n,cmp3);
						count(i,j,k,1,3,2);
					}
				}
				if(max(max(i,j),k) == j){
					sort(a+1,a+1+n,cmp2);
					if(max(i,k) == i){
						sort(a+j+1,a+1+n,cmp1);
						count(i,j,k,2,1,3);
					}
					if(max(i,k) == k){
						sort(a+j+1,a+1+n,cmp3);
						count(i,j,k,2,3,1);
					}
				}
				if(max(max(i,j),k) == k){
					sort(a+1,a+1+n,cmp3);
					if(max(j,i) == j){
						sort(a+k+1,a+1+n,cmp2);
						count(i,j,k,3,2,1);
					}
					if(max(j,i) == i){
						sort(a+k+1,a+1+n,cmp1);
						count(i,j,k,3,1,2);
					}
				}
			}
		}
		cout << ans;
	}
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = 1;
	cin >> t;
	while(t--){
		work();
		if(t) cout << endl; 
	}
} 
