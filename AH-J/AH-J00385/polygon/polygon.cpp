#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
void fs(int now,int he,int step){
	if(step>=3){
		if(a[now]*2<he){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=now+1;i<=n;i++){
		fs(i,he+a[i],step+1);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	fs(0,0,0);
	printf("%lld",ans);
	return 0;
}
