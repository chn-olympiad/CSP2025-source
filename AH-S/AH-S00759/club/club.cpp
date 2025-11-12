#include <bits/stdc++.h>
using namespace std;
int t, n, b[5], ans;
struct xs{
	int b1;
	int b2;
	int b3;
	int b4;
	int b5;
	int b6;
	int b7;
	int k;
}a[100005];
bool cmp5(xs a, xs b){
	return a.b5<b.b5;
}
bool cmp6(xs a, xs b){
	return a.b6<b.b6;
}
bool cmp7(xs a, xs b){
	return a.b7<b.b7;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
		b[1]=b[2]=b[3]=0;
		ans=0;
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d %d %d", &a[i].b1, &a[i].b2, &a[i].b3);
			a[i].b4=max(a[i].b1, max(a[i].b2, a[i].b3));
			a[i].b5=abs(a[i].b1-a[i].b2);
			a[i].b6=abs(a[i].b2-a[i].b3);
			a[i].b7=abs(a[i].b1-a[i].b3);
			if(a[i].b4==a[i].b1)
			    a[i].k=1;
			if(a[i].b4==a[i].b2)
			    a[i].k=2;
			if(a[i].b4==a[i].b3)
			    a[i].k=3;
			ans+=a[i].b4;
			b[a[i].k]++;
		}
	    if(b[1]>n/2){
			int ans1=0, p=0, ans2=0;
			sort(a+1, a+n+1, cmp5);
			for(int i=1; i<=n && p<b[1]-n/2; i++){
				if(a[i].k==1){
				    ans1+=a[i].b5;
				    p++;
				}
			}
			sort(a+1, a+n+1, cmp7);
			p=0;
			for(int i=1; i<=n && p<b[1]-n/2; i++){
				if(a[i].k==1){
				    ans2+=a[i].b7;
				    p++;
				}
			}
			ans-=min(ans1, ans2);
		}
		if(b[2]>n/2){
			int ans1=0, p=0, ans2=0;
			sort(a+1, a+n+1, cmp5);
			for(int i=1; i<=n && p<b[2]-n/2; i++){
				if(a[i].k==2){
				    ans1+=a[i].b5;
				    p++;
				}
			}
			sort(a+1, a+n+1, cmp6);
			p=0;
			for(int i=1; i<=n && p<b[2]-n/2; i++){
				if(a[i].k==2){
				    ans2+=a[i].b6;
				    p++;
				}
			}
			ans-=min(ans1, ans2);
		}
		if(b[3]>n/2){
			int ans1=0, p=0, ans2=0;
			sort(a+1, a+n+1, cmp6);
			for(int i=1; i<=n && p<b[3]-n/2; i++){
				if(a[i].k==3){
				    ans1+=a[i].b6;
				    p++;
				}
			}
			sort(a+1, a+n+1, cmp7);
			p=0;
			for(int i=1; i<=n && p<b[3]-n/2; i++){
				if(a[i].k==3){
				    ans2+=a[i].b7;
				    p++;
				}
			}
			ans-=min(ans1, ans2);
		}
	    printf("%d\n", ans);
	}
    return 0;
}
