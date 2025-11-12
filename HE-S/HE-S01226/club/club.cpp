#include<bits/stdc++.h>
using namespace std;
struct people{
	int my,x,y;
}a[400005];
int t,n;
long long ans;
int p[100005][3];
int m1,m2,m3;
bool cmp(people x,people y){
	return x.my > y.my;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int k = 0;
		ans = 0,m1 = 0,m2 = 0,m3 = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				k++;
				cin >> p[i][j];
				a[k].my = p[i][j];
				a[k].x = i;
				a[k].y = j;
			}
		}
		sort(a+1,a+k+1,cmp);
		for(int i = 1;i <= k;i++){
			if(a[i].y == 1){
				if(m1+1<=n/2 && p[a[i].x][a[i].y]!=1e9){
					m1++;
					ans += a[i].my;
					p[a[i].x][1] = 1e9,p[a[i].x][2] = 1e9,p[a[i].x][3] = 1e9;
				} else{
					continue;
				}
			}
			if(a[i].y == 2){
				if(m2+1<=n/2 && p[a[i].x][a[i].y]!=1e9){
					m2++;
					ans += a[i].my;
					p[a[i].x][1] = 1e9,p[a[i].x][2] = 1e9,p[a[i].x][3] = 1e9;
				} else{
					continue;
				}
			}
			if(a[i].y == 3){
				if(m3+1<=n/2 && p[a[i].x][a[i].y]!=1e9){
					m3++;
					ans += a[i].my;
					p[a[i].x][1] = 1e9,p[a[i].x][2] = 1e9,p[a[i].x][3] = 1e9;
				} else{
					continue;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
