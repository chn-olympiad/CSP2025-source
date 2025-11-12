#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,k,a[N],ans,d[N],tot;
struct node{
	int a,b;
	bool operator <(const node &o) const{
		return b<o.b;
	}
}nn[100000002];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		d[i]=d[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if((j==i?a[i]:d[j]^d[i-1])==k)
				nn[++tot]={i,j};
	sort(nn+1,nn+1+tot);
	int last=nn[1].b;
	if(tot)
		ans=1;
	else{
		cout<<0;
		return 0;
	}
	for(int i=2;i<=tot;i++){
		if(nn[i].a>last){
			last=nn[i].b;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
