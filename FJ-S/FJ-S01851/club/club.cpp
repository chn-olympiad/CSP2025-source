#include<bits/stdc++.h>
using namespace std;
int t,n,ans,maxn,A;
struct club{
	int d1,d2,d3;
}a[100010];
bool cmp1(club a,club b){
	return a.d1>b.d1;
}
bool cmp2(club a,club b){
	return a.d2>b.d2;
}
bool cmp3(club a,club b){
	return a.d3>b.d3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].d1,&a[i].d2,&a[i].d3);
			if(a[i].d2==0&&a[i].d3==0){
				A++;
			}
		}
		ans=0;
		maxn=0;
		stable_sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].d1;
		}
		if(A==n){
			printf("%d\n",ans);
			continue;
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=max(a[i].d2,a[i].d3);
		}
		stable_sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++){
			maxn+=a[i].d2;
		}
		for(int i=n/2+1;i<=n;i++){
			maxn+=max(a[i].d1,a[i].d3);
		}
		maxn=max(maxn,ans);
		ans=0;
		stable_sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].d3;
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=max(a[i].d2,a[i].d1);
		}
		printf("%d\n",max(maxn,ans));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
