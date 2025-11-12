#include<bits/stdc++.h>
using namespace std;
int n,k,b,c,a[1000000],d[1000000],q[3000000],t[2][3000000],cnt=1;
void jia(int x,int y,int z) {
//	printf("%d %d %d\dn",x,y,z);
	if(y==0) {
		q[x]=z;
		return ;
	}
	if(t[y%2][x]==0) t[y%2][x]=++cnt;
	jia(t[y%2][x],y/2,z);
}
int zhao(int x,int y) {
	if(y==0) {
		return q[x];
	}
	if(t[y%2][x]==0) return -1;
	return zhao(t[y%2][x],y/2);
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(a[1]==k) {
		d[1]=1;
		jia(1,k,1);
	}
	c=a[1];
	for(int i=2; i<=n; i++) {
		d[i]=d[i-1];
		c^=a[i];
		b=zhao(1,(c^k));
		jia(1,c,i);
		if(b!=-1) d[i]=max(d[i],d[b]+1);
	}
	printf("%d",d[n]);
	return 0;
}
