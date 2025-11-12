#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005][1005];
long long c(int x,int y) {
	if(x==y)return 1;
	long long ans=1;
	for(int i=0; i<y; i++) {
		ans*=x-i;
	}
	for(int i=2; i<=y; i++) {
		ans/=i;
	}
	return ans;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,maxn=-1,minn=5001;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>m;
		a[i]=m;
		if(m>maxn)maxn=m;
		else if(m<minn)minn=m;
	}
	if(n<3)cout<<0;
	else if(n==3) {
		if(a[0]+a[1]+a[2]>maxn*2)
			cout<<1;
	}
	return 0;
}
