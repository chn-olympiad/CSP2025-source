#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL a[N],lans,rans,n,k,cur;
bool vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1e3){
		for(LL i=1;i<=n;i++){
			cin>>a[i];
		}
		LL ans=0;
		for(LL l=1;l<=n;l++){//從l開始
			for(LL i=l;i<=n;i++){
				cur=cur^a[i];
				if(cur==k){
					lans++;
					cur=0;
				}
			}
			ans=max(ans,lans);
			cur=lans=0;
			cout<<ans;
			return 0;
		}
	}
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		cur=cur^a[i];
		if(cur==k){
			lans++;
			cur=0;
		}
	}
	cur=0;
	for(LL i=n;i>=1;i--){
		cur=cur^a[i];
		if(cur==k){
			rans++;
			cur=0;
		}
	}
	cout<<max(lans,rans);
	return 0;
}
