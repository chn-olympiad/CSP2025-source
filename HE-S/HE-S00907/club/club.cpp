#include<bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 5;
struct people{
	int a1,a2,a3,maxn,midn,minn;
	bool f;
};
people a[N];
bool cmp1(people an, people bn){
	if(an.a1 && !an.a2 && !an.a3 && bn.a1 && !bn.a2 && !bn.a3) return an.a1 > bn.a1;
	else if(an.a1 && !an.a2 && !an.a3) return true;
	else if(bn.a1 && !bn.a2 && !bn.a3) return true;
	else return an.a1 > bn.a1;
}
bool cmp2(people an, people bn){
	if(!an.a1 && an.a2 && !an.a3 && !bn.a1 && bn.a2 && !bn.a3) return an.a2 > bn.a2;
	else if(!an.a1 && an.a2 && !an.a3) return true;
	else if(!bn.a1 && bn.a2 && !bn.a3) return true;
	else return an.a2 > bn.a2;
}
bool cmp3(people an, people bn){
	if(!an.a1 && !an.a2 && an.a3 && !bn.a1 && !bn.a2 && bn.a3) return an.a2 > bn.a2;
	else if(!an.a1 && !an.a2 && an.a3) return true;
	else if(!bn.a1 && !bn.a2 && bn.a3) return true;
	else return an.a2 > bn.a2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		long long sum = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d %d %d", &a[i].a1, &a[i].a2, &a[i].a3);
			a[i].f = true;
			a[i].maxn = max(a[i].a1,max(a[i].a2, a[i].a3));
			a[i].midn = min(a[i].a1,max(a[i].a2, a[i].a3));
			a[i].minn = min(a[i].a1,min(a[i].a2, a[i].a3));
		}
		
		sort(a + 1, a + n + 1, cmp1);
		for(int i = 1; i <= n; i++){
			if(a[i].maxn == a[i].a1 && a[i].f && cnt1+1 <= n / 2){
				sum += a[i].a1;
				cnt1++;
				a[i].f = false;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for(int i = 1; i <= n; i++){
			if(a[i].maxn == a[i].a2 && a[i].f && cnt2+1 <= n / 2){
				sum += a[i].a2;
				cnt2++;
				a[i].f = false;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for(int i = 1; i <= n; i++){
			if(a[i].maxn == a[i].a3 && a[i].f && cnt3+1 <= n / 2){
				sum += a[i].a3;
				cnt3++;
				a[i].f = false;
			}
		}
		//
		sort(a + 1, a + n + 1, cmp1);
		for(int i = 1; i <= n; i++){
			if(a[i].midn == a[i].a1 && a[i].f && cnt1+1 <= n / 2){
				sum += a[i].a1;
				cnt1++;
				a[i].f = false;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for(int i = 1; i <= n; i++){
			if(a[i].midn == a[i].a2 && a[i].f && cnt2+1 <= n / 2){
				sum += a[i].a2;
				cnt2++;
				a[i].f = false;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for(int i = 1; i <= n; i++){
			if(a[i].midn == a[i].a3 && a[i].f && cnt3+1 <= n / 2){
				sum += a[i].a3;
				cnt3++;
				a[i].f = false;
			}
		}
		//
		sort(a + 1, a + n + 1, cmp1);
		for(int i = 1; i <= n; i++){
			if(a[i].minn == a[i].a1 && a[i].f && cnt1+1 <= n / 2){
				sum += a[i].a1;
				cnt1++;
				a[i].f = false;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for(int i = 1; i <= n; i++){
			if(a[i].minn == a[i].a2 && a[i].f && cnt2+1 <= n / 2){
				sum += a[i].a2;
				cnt2++;
				a[i].f = false;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for(int i = 1; i <= n; i++){
			if(a[i].minn == a[i].a3 && a[i].f && cnt3+1 <= n / 2){
				sum += a[i].a3;
				cnt3++;
				a[i].f = false;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
