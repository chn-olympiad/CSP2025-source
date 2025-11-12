#include<bits/stdc++.h>
using namespace std;
int x(int a[],int l,int r) {
	int xsum=a[l];
	for(int i=l+1; i<=r; i++) {
		xsum=a[i] xor xsum;
	}
	return xsum;
}
bool f_q(bool vis[],int l,int r) {
	for(int i=l; i<=r; i++) {
		if(vis[i])return false;
	}
	return true;
}
bool vis[500000]= {0};
int f(int n,int k,int a[],int q,int ans,int l) {
	if(q==n+1)return ans;
	for(int i=l; i<=n; i++) {
		if(x(a,i,i+q-1)==k&&f_q(vis,i,i+q-1)&&i+q-1<=n) {
			++ans;
			for(int j=i; j<=i+q-1; j++)vis[j]=1;
//			cout<<i<<" "<<i+q-1<<endl;
		}
	}
	return f(n,k,a,q+1,ans,l);
}
int main() {
	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	int n,k;
	cin>>n>>k;
	int a[n+1]= {0};
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cout<<f(n,k,a,1,0,1);
	return 0;
}

