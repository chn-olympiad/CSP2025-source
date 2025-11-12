#include<bits/stdc++.h>
#define ll long long
const ll maxn=1e6+1000;
using namespace std;
ll n,k,arr[maxn],yihuhe[maxn],shubiao,zuizhong,cur;
struct da{
	ll l,r;
}ans[maxn];
bool cmp(da diyi,da dier){
	if(diyi.r!=dier.r)return diyi.r<dier.r;
	else if(diyi.l!=dier.l)return diyi.l>dier.l;
	else return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(ll len=0;len<=n;len++){
		for(ll lef=1;lef+len<=n;lef++){
			ll rig=len+lef,cnt=arr[lef];
			for(ll i=lef+1;i<=rig;i++){
				cnt=cnt^arr[i];
			}
			if(cnt==k){
				ans[++shubiao].l=lef;
				ans[shubiao].r=rig;
			}
		}
	}
	sort(ans+1,ans+shubiao+1,cmp);
	zuizhong=1;
	cur=1;
	for(int i=2;i<=shubiao;i++){
		if(ans[i].l>ans[cur].r){
			zuizhong++;
			cur=i;
		}
	}
	cout<<zuizhong;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
