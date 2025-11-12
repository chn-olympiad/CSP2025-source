#include<bits/stdc++.h>
using namespace std;
const int NN=5e5+5;
int n,k,a[NN],vis[NN];
int sa[NN<<2];
//struct node {
//	int l,r;
//};
//bool cmp(node A,node B) {
//	if(A.l==B.l) {
//		if(A.r<B.r) {
//			return A;
//		}
//		return B;
//	}
//}
//vector<pair<int,int> >ans;
int ans;
int ansi[NN],ansj[NN];
bool visi[NN],visj[NN];
//vector<int>ans2;
map<pair<int,int>,int>mp;
bool cmp() {

}
void build(int n,int l,int r) {
	if(l==r) {
		sa[n]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(n<<1,l,mid);
	build(n<<1|1,mid+1,r);
	sa[n]=sa[n<<1]^sa[n<<1|1];
}
int query(int n,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) {
		return sa[n];
	}
	int mid=l+r>>1;
	int res=0;
	if(ql<=mid) {
		res^=query(n<<1,l,mid,ql,qr);
	}
	if(mid<qr) {
		res^=query(n<<1|1,mid+1,r,ql,qr);
	}
	return res;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)  {
		cin>>a[i];
	}
	build(1,1,n);
//	while(1){
//		int op1,op2;
//		cin>>op1>>op2;
//		cout<<query(1,1,n,op1,op2)<<"\n";
//	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int now=query(1,1,n,i,j);
			if(now==k&&vis[i]==0) {
				ans++;
				vis[i]=1;
			}
		}
//	for(unsigned i=0; i<ans.size(); i++) {
//		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
//	}
	}
	cout<<ans;
	return 0;
}

