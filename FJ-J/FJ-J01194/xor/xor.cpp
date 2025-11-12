#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],vis[500005]; 
struct tree{
	int l,r,v;
}tree[2000005];
struct node{
	int l, r; 
};
bool cmp(node a,node b){
	if (a.r - a.l == b.r - b.l) return a.r < b.r;
	return a.r - a.l < b.r - b.l;
}
vector<node> ans;
void build(int u,int l,int r){
	tree[u].l = l,tree[u].r = r;
	if (l == r){
		tree[u].v = a[l];
		return;
	}int mid = (l+r)>>1;
	build(u * 2,l,mid);
	build(u * 2 + 1,mid+1,r);
	tree[u].v = tree[u*2].v ^ tree[u*2+1].v;
}
int query(int u,int l,int r){
	//cout << tree[u].l << "-" << tree[u].r << " " << l << "-" << r << "\n";
	if (tree[u].l >= l && tree[u].r <= r) return tree[u].v;
	int mid = (tree[u].l+tree[u].r)>>1,res = 0;
	if (l <= mid && r <= mid) res ^= query(u*2,l,r);
	else{
		if (l <= mid) res ^= query(u*2,l,mid);
		if (r > mid) res ^= query(u*2+1,mid+1,r);
	}
	return res;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	bool flag = 0;for (int i = 1;i <= n;i++){
		if (a[i] != 1) {
			flag = 1;
			break;
		}
	}
	if (!flag && k == 0){
		cout << n / 2 << "\n";
		return 0;
	}
	build(1,1,n);
	//cout << query(1,1,1) << "\n";
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			int p = query(1,i,j);
			if (p == k) ans.push_back({i,j});
		}
	}int sum = 0;sort(ans.begin(),ans.end(),cmp);
	//for (int i = 0;i < ans.size();i++) cout << ans[i].l << " " << ans[i].r << "\n";
	for (int i = 0;i < ans.size();i++){
		bool flag = 0;for (int j = ans[i].l;j <= ans[i].r;j++){
			if (vis[j]) {
				flag = 1;
				break;
			}
		}if (flag) continue;
		sum++;
		for (int j = ans[i].l;j <= ans[i].r;j++) vis[j]=1;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
