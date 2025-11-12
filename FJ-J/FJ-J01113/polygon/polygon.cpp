#include<bits/stdc++.h>
using namespace std;
const int NN=5005;
const int MOD=998244353;
int n,a[NN];
int sa1[NN],sa2[NN];
void build(int n,int l,int r) {
	if(l==r) {
		sa1[n]=a[l];
		sa2[n]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(n<<1,l,mid);
	build(n<<1|1,mid+1,r);
	sa1[n]=sa1[n<<1]+sa1[n<<1|1];
	sa2[n]=max(sa2[n<<1],sa2[n<<1|1]);
}
int query1(int n,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) {
		return sa1[n];
	}
	int mid=l+r>>1;
	int res=0;
	if(ql<=mid) {
		res+=query1(n<<1,l,mid,ql,qr);
	}
	if(mid<qr) {
		res+=query1(n<<1|1,mid+1,r,ql,qr);
	}
	return res;
}
int query2(int n,int l,int r,int ql,int qr) {
	if(ql<=l&&r<=qr) {
		return sa2[n];
	}
	int mid=l+r>>1;
	int res=-1;
	if(ql<=mid) {
		res=max(res,query2(n<<1,l,mid,ql,qr));
	}
	if(mid<qr) {
		res=max(res,query2(n<<1|1,mid+1,r,ql,qr));
	}
	return res;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)  {
		cin>>a[i];
	}
	build(1,1,n);
//	while(1) {
//		int op1,op2;
//		cin>>op1>>op2;
//		cout<<query2(1,1,n,op1,op2)<<"\n";
//	}
	int cnt=0;
	for(int i=1; i<=n-2; i++) {
		for(int j=i+2; j<=n; j++) {
			int pos1,pos2;
			pos1=query1(1,1,n,i,j);
			pos2=query2(1,1,n,i,j);
			if(pos1>2*pos2){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

