#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a[100015],b[100015],c[100015];
	int d=0,e=0,f=0;
	int n,t,add,k=1;
	int he=0;
	cin>>t;
	if(t==0) {
		cout<<"0";
	}
	for(int i=1; i<=t; i++) {
		cin>>n;
		int lmt = n/2;
		for(int j=1; j<=n; j++) {
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]&&a[j]>c[j]) {
				add=1;
			} else if(b[j]>a[j]&&b[j]>c[j]) {
				add=2;
			} else if(c[j]>a[j]&&c[j]>b[j]) {
				add=3;
			}
			if(add==1 && d==lmt) {
				if(b[j]>c[j]) {
					add=2;
				}
				else{
					add=3;
				}
			}
			if(add==2 && e==lmt) {
				if(a[j]>c[j]) {
					add=1;
				}
				else{
					add=3;
				}
			}
			if(add==3 && f==lmt) {
				if(a[j]>b[j]) {
					add=1;
				}
				else{
					add=2;
				}
			}
			if(d<lmt && add==1) {
				d+=1;
				he+=a[j];
			} else if(e<lmt && add==2) {
				e+=1;
				he+=b[j];
			} else if(f<lmt && add==3) {
				f+=1;
				he+=c[j];
			}
		}
	cout<<he<<endl;
	}
	return 0;
}
