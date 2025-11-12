#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],xjh[500005],lov,cnt,vis[500005];
struct xjhlovezjj{
	int l,r;
}h[10000005];
bool cmp(xjhlovezjj x,xjhlovezjj y){
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(i==1) xjh[i]=a[i];
		else xjh[i]=xjh[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) {
			if(i==1){
				if(xjh[j]==k){
					h[++cnt].l=i;
					h[cnt].r=j;
					break;
				}
			}else{
				if((xjh[j]^xjh[i-1])==k) {
					h[++cnt].l=i;
					h[cnt].r=j;
					break;
				}
			}
		}
	}
	sort(h+1,h+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		bool flag=true;
		for(int j=h[i].l;j<=h[i].r;j++){
			if(vis[j]==true) {
				flag=false;
				break;
			}
		}
		if(flag) {
			for(int j=h[i].l;j<=h[i].r;j++){
				vis[j]=true;
			}
			lov++;
		}
	}
	cout<<lov;
}
