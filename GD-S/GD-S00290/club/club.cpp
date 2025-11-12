#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
bool cmp(node a,node b){
	return a.x > b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n,ans = 0;
		for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y >> a[i].z;
		if(n == 2){
			ans = max(a[1].x+a[2].y,max(a[1].y+a[2].z,a[1].z+a[2].x));
		}else{
			sort(a+1,a+n+1,cmp);
			for(int i = 1;i <= n / 2;i++){
				ans += a[i].x;
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
