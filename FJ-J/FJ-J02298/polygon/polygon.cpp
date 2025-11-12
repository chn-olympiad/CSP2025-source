#include<bits/stdc++.h>
using namespace std;
int a[5100];
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int main(){
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		 for(int j=1;j<i;j++){
		 	for(int k=1;k<j;k++){
		 		for(int l=1;l<k;l++){
		 			if(a[j]+a[k]+a[l]>2*max(a[j],max(a[k],a[l]))){
		 				s++;
		 			}
		 		}
		 	}
		 }
		 for(int j=1;j<i;j++){
		 	for(int k=1;k<j;k++){
		 		for(int l=1;l<k;l++){
		 			for(int m=1;m<l;m++){
			 			if(a[j]+a[k]+a[l]+a[m]>2*max(a[m],max(a[j],max(a[k],a[l])))){
			 				s++;
			 			}
			 		}
		 		}
		 	}
		 }
		 for(int j=1;j<i;j++){
		 	for(int k=1;k<j;k++){
		 		for(int l=1;l<k;l++){
		 			for(int m=1;m<l;m++){
		 				for(int o=1;o<m;o++){
		 					if(a[j]+a[k]+a[l]+a[m]+a[o]>2*max(a[o],max(a[m],max(a[j],max(a[k],a[l]))))){
				 				s++;
				 			}
		 				}
		 			}	
		 		}
		 	}
		 }
	}
	cout<<s;
}
