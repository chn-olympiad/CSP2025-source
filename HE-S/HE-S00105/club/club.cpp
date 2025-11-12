#include <bits/stdc++.h>
using namespace std;

int t,n,sum1,sum2,sum3;
long long ans;
struct node{
	int a1,a2,a3,cha;
}a[100010];

bool cmp(node x,node y){
	return x.cha > y.cha;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		sum1 = 0,sum2 = 0,sum3 = 0,ans = 0;
		scanf("%d",&n);
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a1 == min({a[i].a1,a[i].a2,a[i].a3})){
				a[i].a1 = INT_MIN;
				a[i].cha = abs(a[i].a2 - a[i].a3);
			}
			else if(a[i].a2 == min({a[i].a1,a[i].a2,a[i].a3})){
				a[i].a2 = INT_MIN;
				a[i].cha = abs(a[i].a3 - a[i].a1);
			}else{
				a[i].a3 = INT_MIN;
				a[i].cha = abs(a[i].a2 - a[i].a1);
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i<=n;i++){
			if(a[i].a1 >= a[i].a2 and a[i].a1 >= a[i].a3){
				if(sum1+1 > (n>>1)){
					ans+=a[i].a1-a[i].cha;
				}else{
					ans += a[i].a1;
					sum1++;
				}
			}else if(a[i].a2 >= a[i].a1 and a[i].a2 >= a[i].a3){
				if(sum2+1 > (n>>1)){
					ans+=a[i].a2-a[i].cha;
				}else{
					ans += a[i].a2;
					sum2++;
				}
			}else{
				if(sum3+1 > (n>>1)){
					ans+=a[i].a3-a[i].cha;
				}else{
					ans += a[i].a3;
					sum3++;
				}
			}
		}
		printf("%lld\n",ans);
	}

	return 0;
}
