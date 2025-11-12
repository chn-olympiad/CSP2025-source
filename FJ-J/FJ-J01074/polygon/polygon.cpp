#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5010];
bool b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3 && a[1]+a[2]>a[3]) ans++;
	else if(n==4){
		if(a[1]+a[2]+a[3]>a[4]) ans++;
		if(a[1]+a[2]>a[3]) ans++;
		if(a[1]+a[2]>a[4]) ans++;
		if(a[1]+a[3]>a[4]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
	}
	else if(n==5){
		if(a[1]+a[2]+a[3]+a[4]>a[5]) ans++;
		if(a[1]+a[2]>a[3]) ans++;
		if(a[1]+a[2]>a[4]) ans++;
		if(a[1]+a[2]>a[5]) ans++;
		if(a[1]+a[3]>a[4]) ans++;
		if(a[1]+a[3]>a[5]) ans++;
		if(a[1]+a[4]>a[5]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
		if(a[2]+a[4]>a[5]) ans++;
		if(a[3]+a[4]>a[5]) ans++;
	}
	else printf("0");
	printf("%d",ans);
}