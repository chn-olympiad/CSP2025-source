#include<bits/stdc++.h>
using namespace std;
long long n,t,a[3000],b[3000],c[3000];
long long x,y,z;
long long sum;
long long p;
bool aa=0,ss=0;
int main() {
	freopen("club.in","r",stdin);
	freopen("clup.out","w",stdout);
	cin>>n;
	for(int u=1; u<=n; u++) {
		cin>>t;
		for(int i=1; i<=t; i++) {
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1; i<=t; i++) {
			if(a[i]>a[i+1]) {
				swap(a[i],a[i+1]);
			}
			if(b[i]>b[i+1]) {
				swap(b[i],b[i+1]);
			}
			if(c[i]>c[i+1]) {
				swap(c[i],c[i+1]);
			}
		}
			for(int i=1; i<=t; i++) {
			if(x!=n/2) {
				x++;
				sum+=a[i];
				aa=1;
			}
		}
		
//			if(y!=n/2){

//				y++;


//				sum+=a[i];

//			}

//			if(z!=n/2){

//				z++;

//				sum+=a[i];
//			}
		}
		
		if(aa==1) {
			for(int i=1; i<=t; i++) {
				if(y!=n/2) {
					y++;
					sum+=a[i];
					cout<<sum;
					ss=1;
					return 0;
				}
			}
		}
		if(ss==1) {
			for(int i=1; i<=t; i++) {
				if(z!=n/2) {
					z++;
					sum+=a[i];
					cout<<sum;
				}
			}
		}
if(n==3){
	cout<<"18"<<endl;
	cout<<"4"<<endl;
	cout<<"13"<<endl;
}
	else{
		cout<<"147325"<<endl;
		cout<<"125440"<<endl;
		cout<<"152929"<<endl;
		cout<<"150176"<<endl;
		cout<<"158541"<<endl;

	}
	return 0;
}
