#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100100;
struct node{
	long long v;
	int id;
}a[5],b[N];
bool cmp(node x,node y){
	return x.v >= y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		long long ans = 0;
		int sum[5] = {0};
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[1].v,&a[2].v,&a[3].v);
			a[1].id = 1; a[2].id = 2; a[3].id = 3;
			sort(a+1,a+4,cmp);
			sum[a[1].id]++;
			ans += a[1].v;
			b[i].v = a[1].v-a[2].v;
			b[i].id = a[1].id;
		}
		int s = 0,sx = 0;
		for(int i=1;i<=3;i++){
			if(sum[i] > n/2){
				s = sum[i] - n/2;
				sx = i;
				break;
			}
		}
		if(s == 0){
			printf("%lld\n",ans);
			continue;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=n;s>0;i--){
			if(b[i].id == sx){
				ans -= b[i].v;
				s--;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
