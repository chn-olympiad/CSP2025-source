#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,z1,z2,z3,nn;
	cin>>t;
	long long z;
	for(int ii=1;ii<=t;ii++){
		cin>>n;
		z=0;
		z1=0;
		z2=0;
		z3=0;
		for(int i=1,l,j,m,ll;i<=n;i++){
			cin>>l>>j>>m;
			ll=max(l,max(j,m));
			a[i]=ll-(l+j+m-ll-min(l,min(j,m)));
			z+=ll;
			if(ll==l) z1++;
			else if(ll==j) z2++;
			else z3++;
		}
		if(z1>n/2){
			sort(a+1,a+1+n);
			nn=z1-n/2;
			for(int i=1;i<=nn;i++){
				z-=a[i];
			}
		}
		if(z2>n/2){
			sort(a+1,a+1+n);
			nn=z2-n/2;
			for(int i=1;i<=nn;i++){
				z-=a[i];
			}
		}
		if(z3>n/2){
			sort(a+1,a+1+n);
			nn=z3-n/2;
			for(int i=1;i<=nn;i++){
				z-=a[i];
			}
		}
		cout<<z<<endl;
	}
	return 0;
}
