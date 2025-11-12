#include<bits/stdc++.h>
using namespace std;
int n , ans , T , suma , sumb , sumc;
int now[100005];
bool used[100005];
struct node{
	int x , y , z;
}a[100005];
struct to{
	int type , id , num;
}t[100005];
bool cmp(to A , to B){
	return A.num < B.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;ans = suma = sumb = sumc = 0;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z)now[i] = 1 , suma++;
			else if(a[i].y>a[i].x&&a[i].y>a[i].z)now[i] = 2 , sumb++;
			else if(a[i].z>a[i].x&&a[i].z>a[i].y)now[i] = 3 , sumc++;
			else if(a[i].x==a[i].y&&a[i].y==a[i].z){
				int minsum = min(suma,min(sumb,sumc));
				if(suma==minsum)suma++ , now[i] = 1;
				else if(sumb==minsum)sumb++ , now[i] = 2;
				else sumc++ , now[i] = 3;
			}else if(a[i].x==a[i].y){
				int minsum = min(suma,sumb);
				if(suma==minsum)suma++ , now[i] = 1;
				else sumb++ , now[i] = 2;
			}else if(a[i].x==a[i].z){
				int minsum = min(suma,sumc);
				if(suma==minsum)suma++ , now[i] = 1;
				else sumc++ , now[i] = 3;
			}else if(a[i].z==a[i].y){
				int minsum = min(sumb,sumc);
				if(suma==minsum)sumb++ , now[i] = 2;
				else sumc++ , now[i] = 3;
			}
			if(now[i]==1)ans += a[i].x;
			else if(now[i]==2)ans += a[i].y;
			else ans += a[i].z;
		}
		while(suma>(n>>1)||sumb>(n>>1)||sumc>(n>>1)){
			if(suma>(n>>1)){
				int l = 0;
				for(int i=1;i<=n;i++){
					if(now[i]!=1)continue;
					if(a[i].y<a[i].x||a[i].y==0)t[++l] = {2,i,a[i].x-a[i].y};
					if(a[i].z<a[i].x||a[i].z==0)t[++l] = {3,i,a[i].x-a[i].z};
					used[i] = 0;
				}
				sort(t+1,t+l+1,cmp);
				for(int i=1;i<=l&&suma>(n>>1);i++){
					if(used[t[i].id])continue;
					if(t[i].type==2)sumb++ , ans -= t[i].num , now[t[i].id] = 2;
					else sumc++ , ans -= t[i].num , now[t[i].id] = 3;
					used[t[i].id] = 1 , suma--;
				}
			}
			if(sumb>(n>>1)){
				int l = 0;
				for(int i=1;i<=n;i++){
					if(now[i]!=2)continue;
					if(a[i].x<a[i].y||a[i].x==0)t[++l] = {1,i,a[i].y-a[i].x};
					if(a[i].z<a[i].y||a[i].z==0)t[++l] = {3,i,a[i].y-a[i].z};
					used[i] = 0;
				}
				sort(t+1,t+l+1,cmp);
				for(int i=1;i<=l&&sumb>(n>>1);i++){
					if(used[t[i].id])continue;
					if(t[i].type==1)suma++ , ans -= t[i].num , now[t[i].id] = 1;
					else sumc++ , ans -= t[i].num , now[t[i].id] = 3;
					used[t[i].id] = 1 , sumb--;
				}
			}
			if(sumc>(n>>1)){
				int l = 0;
				for(int i=1;i<=n;i++){
					if(now[i]!=2)continue;
					if(a[i].x<a[i].z||a[i].x==0)t[++l] = {1,i,a[i].z-a[i].x};
					if(a[i].y<a[i].z||a[i].y==0)t[++l] = {2,i,a[i].z-a[i].y};
					used[i] = 0;
				}
				sort(t+1,t+l+1,cmp);
				for(int i=1;i<=l&&sumc>(n>>1);i++){
					if(used[t[i].id])continue;
					if(t[i].type==1)suma++ , ans -= t[i].num , now[t[i].id] = 1;
					else sumb++ , ans -= t[i].num , now[t[i].id] = 2;
					used[t[i].id] = 1 , sumc--;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
