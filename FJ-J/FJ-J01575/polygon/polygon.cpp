#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
long long ans;
bool fl[N];
int n,a[N],p[N],maxx=0;
void f(int x,int maxx,int sum,int cnt){
	sum+=x;
	if(cnt>=3&&sum>=maxx*2) ans++;
	for(int i=cnt+1;i<=n;i++){
		if(!fl[i]){
			fl[i]=1;
			maxx=max(maxx,a[i]);
			f(a[i],maxx,sum,i);
			fl[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f(a[1],a[1],0,1);
	printf("%lld",ans%MOD+1);
	return 0;
}
