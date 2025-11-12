#include<bits/stdc++.h>
using namespace std;
int const N=1e5+10;
int n,a[N],ans;
void f(int s,int t,int maxt,int num){
	if(num>=3&&s+a[t]>maxt){
		ans++;
	}
	if(t<=1){
		return;
	}
	for(int i=t-1;i>=1;i--){
		f(s+a[t],i,maxt,num+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3])ans++;
	for(int i=4;i<=n;i++){
		for(int j=i-1;j>=2;j--)f(0,j,a[i],2);
	}
	printf("%d",ans);
	return 0;
}
