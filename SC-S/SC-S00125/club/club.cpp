#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
vector<int> ht;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	scanf("%lld",&_);
	while(_--){
		int n;
		scanf("%lld",&n);
		int cta=0,ctb=0,ctc=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i] && a[i]>=c[i]) cta++;
			else if(b[i]>=a[i] && b[i]>=c[i]) ctb++;
			else ctc++;
			ans+=max({a[i],b[i],c[i]});
		}
		int ct=max({cta,ctb,ctc});
		if(ct<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		ht.clear();
		for(int i=1;i<=n;i++){
			if(ct==cta && a[i]>=b[i] && a[i]>=c[i]) ht.push_back(a[i]-max(b[i],c[i]));
			else if(ct==ctb && b[i]>=a[i] && b[i]>=c[i]) ht.push_back(b[i]-max(a[i],c[i]));
			else if(ct==ctc && c[i]>=a[i] && c[i]>=b[i]) ht.push_back(c[i]-max(a[i],b[i]));
		}
		sort(ht.begin(),ht.end());
		for(int i=0;i<ct-n/2;i++) ans-=ht[i];
		printf("%lld\n",ans);
	}
	return 0;
}