#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s,ans=1,sum[500005],cnt;
struct node{
	int l,r;
}vis[500005];
int f(int x){
	for(int i=x;i<=n;i++){
		if((sum[i]^sum[x-1])==k)return i;
	}
	return -1;
}
int cmp(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int t=f(i);
		if(t!=-1){
			vis[++cnt].l=i;
			vis[cnt].r=t;
		}
	}
	sort(vis+1,vis+cnt+1,cmp);
	if(cnt==0){
		cout<<0;
		return 0;
	}
	int t=vis[1].r;
	for(int i=2;i<=cnt;i++){
		if(vis[i].l>t){
			t=vis[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

