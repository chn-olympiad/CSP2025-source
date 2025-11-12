#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,a[500005],sxor[500005],ans;
struct Node{
	LL l,r;
};
bool cmp(const Node &x,const Node &y){
	return x.r<y.r;
}
vector<Node> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(LL i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sxor[i]=sxor[i-1]^a[i];
	}
	for(LL i=1;i<=n;i++)
		for(LL j=1;j<=i;j++)
			if((sxor[i]^sxor[j-1])==k) v.push_back({j,i});
	sort(v.begin(),v.end(),cmp);
	LL R=0;
	LL len=v.size();
	for(LL i=0;i<len;i++){
		if(v[i].l>R){
			ans++;
			R=v[i].r;
		}
	}
	printf("%lld",ans);
	return 0;
}
