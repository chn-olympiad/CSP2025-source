#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct node{
	int x,y,z;
	friend bool operator<(node a,node b){
		if(a.x == b.x && a.y == b.y) return a.z > b.z;
		else if(a.x == b.x) return a.y > b.y;
		else return a.x > b.x;
	}
}a[100100]; 
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--){
		ans = 0; 
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		sort(a + 1,a + 1 + n);
		int cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 1;i <= n;i++){
			int ma = -1,ma_id = 0;
			if(a[i].x == max({a[i].x,a[i].y,a[i].z})){
				ma_id = 1;
				if(cnt1 < n / 2){
					ans = ans + a[i].x;
					cnt1++;
				} 
				else{ // 次小 
					if(a[i].y == max(a[i].y,a[i].z)){
						if(cnt2 < n / 2){
							ans = ans + a[i].y;
							cnt2++;
						}
						else{
							if(cnt3 < n / 2){
								ans = ans + a[i].z;
								cnt3++;
							}
						}
					}
					else{
						if(cnt3 < n / 2){
							ans = ans + a[i].z;
							cnt3++;
						}
						else{
							if(cnt2 < n / 2){
								ans = ans + a[i].y;
								cnt2++;
							}
						}
					}
				}
			}
			else if(a[i].y == max({a[i].x,a[i].y,a[i].z})){
				ma_id = 2;
				if(cnt2 < n / 2){
					ans = ans + a[i].y;
					cnt2++;
				} 
				else{ // 次小 
					if(a[i].x == max(a[i].x,a[i].z)){
						if(cnt1 < n / 2){
							ans = ans + a[i].x;
							cnt1++;
						}
						else{
							if(cnt3 < n / 2){
								ans = ans + a[i].z;
								cnt3++;
							}
						}
					}
					else{
						if(cnt3 < n / 2){
							ans = ans + a[i].z;
							cnt3++;
						}
						else{
							if(cnt1 < n / 2){
								ans = ans + a[i].x;
								cnt1++;
							}
						}
					}
				}
			}
			else if(a[i].z == max({a[i].x,a[i].y,a[i].z})){
				ma_id = 1;
				if(cnt3 < n / 2){
					ans = ans + a[i].z;
					cnt3++;
				} 
				else{ // 次小 
					if(a[i].y == max(a[i].y,a[i].x)){
						if(cnt2 < n / 2){
							ans = ans + a[i].y;
							cnt2++;
						}
						else{
							if(cnt1 < n / 2){
								ans = ans + a[i].x;
								cnt1++;
							}
						}
					}
					else{
						if(cnt1 < n / 2){
							ans = ans + a[i].x;
							cnt1++;
						}
						else{
							if(cnt2 < n / 2){
								ans = ans + a[i].y;
								cnt2++;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
