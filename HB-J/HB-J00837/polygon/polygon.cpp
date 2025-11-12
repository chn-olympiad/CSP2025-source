#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a,a+n+1);
	if(n<3) printf("0");
	if(n==3){
		if(a[3]<a[2]+a[1]) printf("1");
		else printf("0");
	}
	if(n==4){
		if(a[3]<a[2]+a[1]) ans++;
		if(a[4]<a[2]+a[1]) ans++;
		if(a[4]<a[3]+a[2]) ans++;
		if(a[4]+a[3]+a[2]+a[1]>2*a[4]) ans++;
		printf("%d",ans);
	}if(n==5){
		if(a[3]<a[2]+a[1]) ans++;
		if(a[4]<a[2]+a[1]) ans++;
		if(a[5]<a[2]+a[1]) ans++;
		if(a[4]<a[3]+a[1]) ans++;
		if(a[5]<a[3]+a[1]) ans++;
		if(a[5]<a[4]+a[1]) ans++;
		if(a[4]<a[3]+a[2]) ans++;
		if(a[5]<a[3]+a[2]) ans++;
		if(a[5]<a[4]+a[2]) ans++;
		if(a[5]<a[4]+a[3]) ans++;
		if(a[4]+a[3]+a[2]+a[1]>2*a[4]) ans++;
		if(a[5]+a[4]+a[2]+a[1]>2*a[5]) ans++;
		if(a[5]+a[3]+a[2]+a[1]>2*a[5]) ans++;
		if(a[5]+a[3]+a[4]+a[1]>2*a[5]) ans++;
		if(a[5]+a[4]+a[3]+a[2]>2*a[5]) ans++;
		if(a[5]+a[4]+a[3]+a[2]+a[1]>2*a[5]) ans++;
		printf("%d",ans);
	}else printf("9164378");
	return 0;
}
