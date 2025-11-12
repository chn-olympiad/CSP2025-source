#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long int ans;
void f(int pos,int sum,int cnt,int rc,int maxn){
	if(rc==cnt){
		if(sum>maxn*2)ans++;
		return;
	}
	if(pos<=n&&rc<cnt){
		f(pos+1,sum+a[pos],cnt,rc+1,a[pos]);
		f(pos+1,sum,cnt,rc,maxn);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		f(1,0,i,0,0);
	}
	printf("%lld",ans%998244353);
	return 0;
}