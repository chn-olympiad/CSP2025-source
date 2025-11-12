#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,num[4*maxn],a[maxn],ans; 
struct edge{
	int l,r;
};
vector<edge>v,f;
bool cmp(edge a,edge b){
	return a.r-a.l<b.r-b.l;
}
void build(int l,int r,int now){
	if(l==r){
		num[now]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now<<1);
	build(mid+1,r,now<<1|1);
	num[now]=num[now<<1]^num[now<<1|1];
}
int query(int l,int r,int now,int nl,int nr){
	if(nl<=l&&nr>=r){
		return num[now];
	}
	int mid=(l+r)>>1,ans=0;
	if(nl<=mid)ans^=query(l,mid,now<<1,nl,nr);
	if(nr>mid)ans^=query(mid+1,r,now<<1|1,nl,nr);
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	for(int i=1;i<=n;i++){
		if(a[i]==k)v.push_back({i,i});
		for(int j=i+1;j<=n;j++){
			if(query(1,n,1,i,j)==k){
				v.push_back({i,j});
				break;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		bool flag=0;
		for(int j=0;j<f.size();j++){
			if((v[i].r>=f[j].l&&v[i].l<=f[j].l)||(v[i].r>=f[j].r&&v[i].l<=f[j].l)||(v[i].l>=f[j].l&&v[i].l<=f[j].r&&v[i].r>=f[j].r)){
				flag=1;
				break;
			}
		}
		if(!flag)f.push_back({v[i].l,v[i].r});
	}
	cout<<f.size();
	return 0;
}
