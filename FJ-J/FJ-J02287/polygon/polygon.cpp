#include<bits/stdc++.h>
using namespace std;
int c(int z,int p){
	int rr=1,r=1;
	for(int i=1; i<=p; i++){
		rr*=i;
	}
	for(int i=z-p+1; i<=z; i++){
		r*=i;
	}
	return r/rr;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5555],x=0;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	/*for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int s=0,m=-11;
			for(int k=i; k<=j; k++){
				s+=a[k];
				if(a[k]>m){
					m=a[k];
				}
			}
			if(2*m<=s && (j-i+1)>=3){
				x++;
				cout<<i<<j<<"\n";
			}
		}
	}*/
	for(int i=3; i<=n; i++){
		x+=c(n,i);
	}
	cout<<x%998244353;
}
