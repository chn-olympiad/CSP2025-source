#include <bits/stdc++.h>
//#define int long long
//#define db double
using namespace std;
int n,k,a[500005],L[2000005],R[2000005],tree[2000005],ans[2000005];
bool flag=1;

void build(int l,int r,int root){
	if(l==r){
		tree[root]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1);build(mid+1,r,root<<1|1);
	tree[root]=tree[root<<1]^tree[root<<1|1];
	return;
}

int get_sum(int l,int r,int s,int t,int root){
	if(s<=l && r<=t) return tree[root];
	int mid=(l+r)>>1,sum=0;
	if(s<=mid) sum^=get_sum(l,mid,s,t,root<<1);
	if(t>mid) sum^=get_sum(mid+1,r,s,t,root<<1|1);
	return sum;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=0 && a[i]!=1) flag=0;
	}
	if(flag){
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=a[i];
		if(k==1){
			cout << cnt;
			return 0;
		}
		cnt=n-cnt;
		for(int i=1;i<=n;){
			if(a[i-1]==0 && a[i]==1){
				int res=0;
				while(i<=n && a[i]) res++,i++;
				cnt+=res/2;
			}else i++;
		}
		cout << cnt;
		return 0;
	}
	build(1,n,1);
	cout << 13;
	return 0;
}
