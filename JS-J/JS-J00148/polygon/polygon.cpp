#include<bits/stdc++.h>
using namespace std;

int n;
int a[5200];
long long s[5200];
int tree[52000];
int ls(int p){
	return p<<1;
}
int rs(int p){
	return p<<1|1;
}

int mm(int l,int r){
	return l + ((r-l)>>1);
}
void push_up(int p){
	tree[p] = tree[ls(p)] + tree[rs(p)];
	return ;
}
void build(int l,int r,int p){
	if(l==r){
		tree[p] = a[l];
		return ;
	}
	int mid = mm(l,r);
	build(l,mid,ls(p));
	build(mid+1,r,rs(p));
	push_up(p);
	return ;
}
int query(int l,int r,int ql,int qr,int p){
	if(qr<l||r<ql){
		return 0;
	}
	if(ql<l&&r<qr){
		return tree[p];
	}
	int mid = mm(l,r);
	int ans = 0;
	if(l<=mid) ans=max(ans,query(l,mid,ql,qr,ls(p)));
	if(mid+1<=r) ans=max(ans,query(mid+1,r,ql,qr,rs(p)));
	return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i] = s[i-1] + a[i];
	}
	
	build(1,n,1);

	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long sum = s[j] - s[i-1];
			long long maxv = query(1,n,i,j,1);
			if(sum>2*maxv) ans++;
		}
	}

	printf("%d\n",ans);
    return 0;
}
