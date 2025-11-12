#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int MAXN=5e5+5;
vector<pair<int,int> > ans;
struct node{
	int l,r,sum;
}tr[5*MAXN];
bitset<MAXN> vis;
int a[MAXN];
void pushup(int p){
	tr[p].sum=tr[lc].sum^tr[rc].sum;
}
void build(int p,int l,int r){
	tr[p]={l,r,a[l]};
	if(l==r)return;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
int query(int p,int l,int r){
	if(tr[p].r<l||tr[p].l>r)return 0;
	if(l<=tr[p].l&&tr[p].r<=r)return tr[p].sum;
	return(query(lc,l,r)^query(rc,l,r));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(query(1,i,j)==k){
				ans.push_back(make_pair(i,j));
			}
		}
	}
	sort(ans.begin(),ans.end());
	int len=ans.size();
//	for(int i=0;i<len;i++){
//		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
//	}
//	cout<<'\n';
	for(int i=0;i<len;i++){
		if(vis[i])continue;
		for(int j=i+1;j<len;j++){
			if(ans[i].second>=ans[j].first){
				if(ans[i].second-ans[i].first>=ans[j].second-ans[j].first){
//					cout<<ans[i].first<<' '<<ans[i].second<<'\n';
//					cout<<ans[i].second<<' '<<ans[i].first<<' '<<ans[j].second<<' '<<ans[j].second<<'\n';
					vis[i]=1;
					break;
				}else{
//					cout<<ans[j].first<<' '<<ans[j].second<<'\n';
//					cout<<ans[i].second-ans[i].first<<' '<<ans[j].second-ans[j].second<<'\n';
					vis[j]=1;
				}
			}
		}
	}
	int cnt=0;
	for(int i=0;i<len;i++){
		if(!vis[i]){
//			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
			cnt++;
		}
	}
//	cout<<'\n';
	cout<<cnt;
	return 0;
}
