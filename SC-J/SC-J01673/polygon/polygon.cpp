#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int a[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a,a+n+1);
	if(n==3&&a[3]<(a[1]+a[2]))ans=1;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//骗分，特殊性质n≤3、ai≤1。