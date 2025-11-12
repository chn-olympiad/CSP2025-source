//xor 50
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll n,m,tot,cnt;
int a[N];
int sum[N];
struct q{
	int l,r;
}h[(int)1e6+7];
bool cmp(q x,q y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&a[i]==m){
				tot++;
				h[tot].l=i,h[tot].r=j;
			}
			else if((sum[j]^sum[i-1])==m){
				tot++;
				h[tot].l=i,h[tot].r=j;
			}
		}
	}
	sort(h+1,h+1+tot,cmp);
	int o=0;
	for(int i=1;i<=tot;i++){
		if(h[i].l>o) o=h[i].r,cnt++;
	}
	cout<<cnt;
	return 0;
}
