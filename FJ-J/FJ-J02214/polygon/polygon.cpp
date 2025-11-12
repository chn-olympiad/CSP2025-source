#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans;
void f(int k,int sum,int t){
	for(int i=t+1;i<=n-k+1;i++){
		if(k==1){
			if(a[i]<sum) ans++;
		}
		else f(k-1,sum+a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(n==3 && a[1]+a[2]>a[3]) printf("%d\n",1);
		else printf("%d\n",0);
	}else{
		for(int i=3;i<=n;i++){
			f(i,0,0);
		}
		printf("%d\n",ans);
	}

	return 0;
}
