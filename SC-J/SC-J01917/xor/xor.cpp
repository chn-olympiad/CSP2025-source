#include<bits/stdc++.h>
using namespace std;
#define lid (id<<1)
#define rid ((id<<1)|1)
const int N=1048577;
int n,k,ans;
int a[N];
int s[N];
int r[N];
int lst[N];
int dp[N][2];
map<int,int> mp;
struct TREE{
	int l,r;
	int mx;
}tr[1048577*4];
void build(int id,int l,int r){
	tr[id].l=l;
	tr[id].r=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lid,l,mid);
	build(rid,mid+1,r);
}
void modify(int id,int x,int v){
	if(tr[id].l==tr[id].r){
		tr[id].mx=v;
		return;
	}
	int mid=(tr[id].l+tr[id].r)>>1;
	if(x<=mid)
		modify(lid,x,v);
	else
		modify(rid,x,v);
	tr[id].mx=max(tr[lid].mx,tr[rid].mx);
}
int ask(int id,int l,int r){
	if(tr[id].l==l&&tr[id].r==r)
		return tr[id].mx;
	int mid=(tr[id].l+tr[id].r)>>1;
	if(r<=mid)
		return ask(lid,l,r);
	else if(l>=mid+1)
		return ask(rid,l,r);
	return max(ask(lid,l,mid),ask(rid,mid+1,r));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=n;i>=1;i--){
		if(mp[s[i]]==0)
			mp[s[i]]=i;
		mp[s[i]]=min(mp[s[i]],i);
		r[i]=mp[s[i-1]^k];
	}
	build(1,0,1048577);
	for(int i=1;i<=n;i++){
		if(i-1>=1)
			lst[i]=ask(1,1,i-1);
		modify(1,r[i],i);
	}
	for(int i=1;i<=n;i++){
		if(!r[i]) continue;
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=max(dp[lst[i]][1],dp[lst[i]][0])+1;
	}
	for(int i=n;i>=1;i--)
		if(r[i]){
			ans=max(dp[i][0],dp[i][1]);
			break;
		}
	cout<<ans;
	return 0;
}