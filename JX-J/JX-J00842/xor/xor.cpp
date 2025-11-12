#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],t[2000005],ans;
void build(long long fa,long long l,long long r){
	if(l==r){
		t[fa]=a[l];
		return;
	}
	long long mid=(l+r)/2;
	build(fa*2,l,mid);
	build(fa*2+1,mid+1,r);
	t[fa]=t[fa*2]^t[fa*2+1];
}
long long query(long long ql,long long qr,long long l,long long r,long long fa){
	if(ql<=l&&r<=qr)return t[fa];
	long long num,x=-1,y=-1;
	long long mid=(l+r)/2;
	if(ql<=mid)x=query(ql,qr,l,mid,fa*2);
	if(mid<qr)y=query(ql,qr,mid+1,r,fa*2+1);
	if(x==-1)return y;
	if(y==-1)return x;
	if(x!=-1&&y!=-1){
		num=x^y;
		return num;
	}
	return 0;
}
void dfs(long long l,long long r,long long cnt){
	long long num=query(l,r,1,n,1);
	if(num!=k)return;
	if(l>n||r>n)return;
	if(r==n){
		if(num==k)ans=max(ans,cnt+1);
		return;
	}
	if(num==k){
		for(int i=1;i<=n-r;i++){
			for(int j=r+1;j<=n-i+1;j++){
				if(query(j,j+i-1,1,n,1)==k)dfs(j,j+i-1,cnt+1);
			}
		}
	}
	else return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(k==1&&a[i]==1)ans++;
	}
	if(k==1){
		cout<<ans;
		return 0;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		dfs(1,1+i-1,0);
	}
	cout<<ans;
	return 0;
}
