#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],z,ap,bp,cp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>b[j]&&a[j]>c[j]){
				ap++;
				z+=a[j];
			}
			if(a[j]<b[j]&&b[j]>c[j]){
				ap++;
				z+=b[j];
			}
			if(a[j]<c[j]&&b[j]<c[j]){
				bp++;
				z+=b[j];
			}
		}
		cout<<z;
	}
	return 0;
} 
