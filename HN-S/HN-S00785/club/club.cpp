#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n,t,r,x;
	long long a[10001],b[10001],c[10001],d[10001],e[10001];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;

	for(int z=1; z<=n; z++) {
		cin>>t;
		r=t/2;
		x=0;
		for(int i=1; i<=t; i++) {
			cin>>a[i]>>b[i]>>c[i];
		}


		for(int i=1; i<=t-1; i++) {
			for(int j=1; j<=t; j++) {
				if(a[j]<a[j+1]) swap(a[j],a[j+1]);
			}
		}

		for(int i=1; i<=t-1; i++) {
			for(int j=1; j<=t; j++) {
				if(b[j]<b[j+1]) swap(b[j],b[j+1]);
			}
		}

		for(int i=1; i<=t-1; i++) {
			for(int j=1; j<=t; j++) {
				if(c[j]<c[j+1]) swap(c[j],c[j+1]);
			}
		}
		x=0;
		for(int i=1; i<=r; i++) d[i]+=a[i];
		for(int i=r+1; i<=2*r; i++) d[i]+=b[i-r];
		for(int i=2*r+1; i<=3*r; i++) d[i]+=c[i-r*2];

		for(int i=1; i<=3*r; i++) {
			for(int j=1; j<=3*r; j++) {
				if(d[j]<d[j+1]) swap(d[j],d[j+1]);
			}
		}
		for(int i=1; i<=t; i++) {
			x+=d[i];
		}

		e[z]=x;
		cout<<z;
	}
	for(int i=1; i<=n; i++) cout<<e[i]<<endl;
	return 0;
}

