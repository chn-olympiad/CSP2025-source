#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e3+10,inf=998244353;
int n,a[N];
long long ans;
void f(int x,int sum,int mx,int cnt)
{
	if(x==n+1){
		if(sum>mx*2&&sum!=0&&cnt>=3){
			ans++;
			ans%=inf;
		}
		return;
	}
	f(x+1,sum+a[x],max(mx,a[x]),cnt+1);
	f(x+1,sum,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f(1,0,-1,0);
	printf("%lld",ans%inf);
	return 0;
}
