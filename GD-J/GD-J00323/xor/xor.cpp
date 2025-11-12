#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500005],ans,p[500005],t,cntt;
struct re{
	ll x,y;
}e[500005];
bool cmp(re x,re y){
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		ll sum=a[i];
		if(a[i]==k){
			e[++t].x=i;
			e[t].y=i;
		}
		for(int j=i+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				e[++t].x=i;
				e[t].y=j;
			}
		}
	}
	sort(e+1,e+t+1,cmp);
	int las;
	for(int i=1;i<=t;i++)
	{
		if(e[i].x>las){
			ans++;
			las=e[i].y;
		}
	}
	printf("%lld",ans);
}
