#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int b1;
	int b2;
	int b3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> m;
	while(m--){
		cin >> n;
		int ans = 0;
		node a[100005] ={0};
		for(int i = 1; i <= n; i++){
			cin >> a[i].b1 >> a[i].b2 >> a[i].b3;
		}
		if(a[1].b2 == 0 && a[1].b3 == 0){
			for(int i = 1; i <= n; i++){
				ans += a[i].b1;
			}
		}else{
			int x = 0;int y=0;
			for(int i = 1; i <= n; i++){
				if(a[i].b1 > a[i].b2 && x < n/2){
					ans+=a[i].b1;
					x++;
				}else if(y < n /2){
					ans+=a[i].b2;
					y++;
				}else{
					ans+=0;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
