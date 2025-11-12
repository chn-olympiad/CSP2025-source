#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t;
int a[N][5],f[N];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int tmp=n/2;
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=3;j++){
	    		cin>>a[i][j];
			}
	    }	
		for(int i=1;i<=n;i++){
			for(int j=n;j>=1;j--){
				for(int k=1;k<=3;k++){ 
					f[j]=max(f[j],f[j-1]+a[i][k]);
				}
			}
		}
		cout<<f[n];
    }
	return 0;
} 
