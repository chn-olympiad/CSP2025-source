#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,k,t=0;
ll a[N],ans=0;
struct Line{
	int l,r;
	bool operator < (const Line&A){
		return r<A.r;
	}
}b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				b[++t]=Line{i,j};
			}
		}
	}
	sort(b+1,b+t+1);
	int e=0;
	for(int i=1;i<=t;i++){
		if(b[i].l>e){
			ans++;
			e=b[i].r;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
