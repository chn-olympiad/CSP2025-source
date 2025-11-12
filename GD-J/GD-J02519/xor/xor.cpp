#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define int long long
int n,m,j,k,l,q,cnt;
int sum[N],x[N];
struct NOIP{
	int l,r;
}y[N];
bool cmp(NOIP i,NOIP j){
	if(i.r!=j.r)return i.r<j.r;
	return i.l<j.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		sum[i]=sum[i-1]^x[i];
	}
	for(int i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				y[++q].l=i;
				y[q].r=j;
			}
		}
	}
	sort(y+1,y+1+q,cmp);
	int r=0;
	for(int i=1;i<=q;i++){
		if(r<y[i].l){
			cnt++;
			r=y[i].r;
		}
	}
	printf("%lld",cnt);
	return 0;
}
