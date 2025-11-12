#include <bits/stdc++.h>
using namespace std;
struct lty{
	int id,v;
	inline friend bool operator<(const lty&x,const lty&y){
		return x.v > y.v;
	} 
} a[100005][4];

int t,n;
long long ans = 0;
int c[4];
inline void sv(){
    priority_queue<lty> q;
    ans = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++) scanf("%d",&a[i][j].v),a[i][j].id = j;
		sort(a[i] + 1,a[i] + 4);
		q.push({a[i][1].id,a[i][1].v - a[i][2].v});
	}
	for(int i = 1;i <= 3;i++) c[i] = 0;
	for(int i = 1;i <= n;i++) c[a[i][1].id]++,ans += a[i][1].v;
	int tc = 0;
	for(int i = 1;i <= 3;i++){
		if(c[i] > n / 2){
			tc = i;
			break;
		} 
	}
	/*if(!tc){
		printf("%lld\n",ans);
		return;
	}*/
	while(c[tc] > n / 2){
		while(q.top().id != tc) q.pop();
		lty p = q.top();q.pop();
		ans -= p.v;
		c[tc]--;
	}
	printf("%lld\n",ans);
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) sv();
	return 0;
}
