#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,a[100000][3],mx=-1,c=0;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
		 }
		}
		for(int j=0;j<n;j++){
			for(int k=0;k=3;k++){
				if(a[j][k]>mx) mx=a[j][k];
			}
			c+=mx;
			mx=0;
		}
		cout<<c<<endl;	
	}
	return 0;
}

