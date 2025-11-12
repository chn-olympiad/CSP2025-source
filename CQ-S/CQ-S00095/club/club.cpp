#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[4],ans,c,px[5],mx,mi,ma;
struct node{
	ll num,ma,mi;
};
bool operator<(node A,node B){
	return A.num > B.num; 
}
priority_queue<node> pq1,pq2,pq3;
int main(){
//	freopen("club.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		while(!pq1.empty()) pq1.pop();
		while(!pq2.empty()) pq2.pop();
		while(!pq3.empty()) pq3.pop();
		ans = 0;
		scanf("%lld",&n);
		for(int i = 1; i <= n; i++){
			scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
			px[1] = a[1],px[2] = a[2],px[3] = a[3];
			sort(px+1,px+4);
			if(a[1] == px[2]){
				mi = 1;
				if(a[2] == px[3]) mx = 2;
				else mx = 3;
			}else if(a[2] == px[2]){
				mi = 2;
				if(a[1] == px[3]) mx = 1;
				else mx = 3;
			}else{
				mi = 3;
				if(a[2] == px[3]) mx = 2;
				else mx = 1;
			}
			if(mx == 1){
				if(pq1.size() != n/2){
					pq1.push(node{a[1]-a[mi],1,mi});
					ans += a[1];
				}else{
					if(a[1]-a[mi] > pq1.top().num){
						ans -= pq1.top().num;
						pq1.pop();
						pq1.push(node{a[1]-a[mi],1,mi});
						ans += a[1];
					}else{
						ans += a[mi]; 
					}
				}
			}else if(mx == 2){
				if(pq2.size() != n/2){
					pq2.push(node{a[2]-a[mi],1,mi});
					ans += a[2];
				}else{
					if(a[2]-a[mi] > pq2.top().num){
						ans -= pq2.top().num;
						pq2.pop();
						pq2.push(node{a[2]-a[mi],1,mi});
						ans += a[2];
					}else{
						ans += a[mi]; 
					}
				}
			}else{
				if(pq3.size() != n/2){
					pq3.push(node{a[3]-a[mi],1,mi});
					ans += a[3];
				}else{
					if(a[3]-a[mi] > pq3.top().num){
						ans -= pq3.top().num;
						pq3.pop();
						pq3.push(node{a[3]-a[mi],1,mi});
						ans += a[3];
					}else{
						ans += a[mi]; 
					}
				}
			}
//			printf("%d %lld %lld %lld %lld %lld %lld\n",i,mx,mi,ans,a[1],a[2],a[3]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
          _____    ____
   /\    |        /    \
  /__\   |_____   |    |
 /    \  |        |    |
/      \ |        \____/  

*/
