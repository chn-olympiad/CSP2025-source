#include<bits/stdc++.h>
using namespace std;
int t, n, xmax, ymax, zmax, limit, ans1 = 0, ans2 = 0, ans3 = 0, ans = 0;
struct People{
	int x, y, z;
	
};
int cmp1(const People& a , const People& b)
      { return b.x > a.x;};

int cmp2(const People& a , const People& b) 
      { return b.y > a.y;};
      
int cmp3(const People& a , const People& b) 
      { return b.z > a.z;};  

People arr[100005];

int arrx[100005];
int arry[100005];
int arrz[100005];
int f[100005][3][2];
int main(){
	freopen("club.in", "r" , stdin);
	cin >> t;
	while(t--){
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
		ans = 0;
		cin >> n;
		limit = n/2;
		for(int i = 1; i<=n ; i++){
			cin >> arr[i].x >> arr[i].y >> arr[i].z;
			arrx[i] = arr[i].x;
			arry[i] = arr[i].y;
			arrz[i] = arr[i].z;
			xmax = max(arr[i].x, xmax);
			ymax = max(arr[i].y, ymax);
			zmax = max(arr[i].z, zmax);
		}
		if(ymax == 0 && zmax == 0){
			sort(arrx+1, arrx+n+1);
			for(int i = n; i>limit ; i--){
				ans += arrx[i];
			}
				cout << ans << endl;
				continue;
		}
		sort(arr+1, arr+n+1 , cmp1);
		for(int i = n; i>limit ; i--){
			ans1 += arr[i].x;
		}
		for(int i = limit ; i>0 ;  i--){
			ans1 += max(arr[i].y, arr[i].z);
		}
		
		sort(arr+1, arr+n+1 , cmp2);
		for(int i = n; i>limit ; i--){
			ans2 += arr[i].y;
		}
		for(int i = limit ; i>0 ;  i--){
			ans2 += max(arr[i].x, arr[i].z);
		}
		
		sort(arr+1, arr+n+1 , cmp3);
		for(int i = n; i>limit ; i--){
			ans3 += arr[i].z;
		}
		for(int i = limit ; i>0 ;  i--){
			ans3 += max(arr[i].y, arr[i].x);
		}
		ans = max( ans1, max(ans2, ans3));
		cout << ans << endl;
	}
	freopen("club.out", "w" , stdout);
	return 0;
}
