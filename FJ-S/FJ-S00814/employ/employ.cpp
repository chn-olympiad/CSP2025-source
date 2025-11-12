#include<bits/stdc++.h>
using namespace std;
char b;
int n,m,s,z,u=998244353,a[501],q[501],d[501];
void f(int w,int r){
	if(m<=r){
		z=1;
		for(int i=n-w+1;i;i--) z=z*i%u;
		s=(s+z)%u;
	}else if(w>n) return;
	for(int i=1;i<=n;i++) if(!d[i]) d[i]=1,f(w+1,r+(a[i-1]<q[w]&&a[i]==a[i-1])),d[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b,a[i]=a[i-1]+'1'-b;
	for(int i=1;i<=n;i++) cin>>q[i];
	f(1,0),cout<<s;
	return 0;
}
