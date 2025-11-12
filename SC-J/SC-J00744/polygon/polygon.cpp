#include<bits/stdc++.h>
using namespace std;
#define MOD 998224353
int n;
long long ans=0;
int a[5005];

void polygon(int cnt,int Max,int m,int idex) {
	if(m > n)return;
	if(m >= 3 && cnt > (Max<<1)) {
		++ans;
		ans%=MOD;
	}
	for(int i=idex; i<=n; ++i) {
		int New_max=max(Max,a[i]);
		int New_cnt=cnt+a[i];
		++m;
		++idex;
		polygon(New_cnt,New_max,m,idex);
	}
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) {
		scanf("%d",&a[i]);
	}
	polygon(0,0,0,1);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}