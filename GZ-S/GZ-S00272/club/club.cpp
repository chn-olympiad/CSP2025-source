#include<bits/stdc++.h>
using namespace std;
int a[4];
int b[100001];
int w[1000];
int main(){
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	int t,n,k,m=0;
	cin>>t;
    for(int i=1;i<=t;++i){
    	cin>>n;
    	for(int j=1;j<=n;++j){
    		for(int h=1;h<=3;++h){
    			cin>>a[h];
			}
			
    	for(int u=1;u<=3;++u){
    		for(int d=1;d<=3;++d){
    			if(a[d]<a[d+1]){
    				k=a[d];
    				a[d]=a[d+1];
    				a[d+1]=k;
				}
			}
		}
		b[j]=a[1];
		
			w[i]=w[i]+b[j];
	}
		}
	for(int r=1;r<=t;++r){
		cout<<w[r];
	}
	return 0;
}
