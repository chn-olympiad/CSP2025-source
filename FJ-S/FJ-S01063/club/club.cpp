#include<bits/stdc++.h>
using namespace std;
int n,T;
int a[2005][2005];
int main(){
    freopen("club.in","r",stdio);
	freopen("club.out,"w",stdio);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		int zs=0;
		for(int i=1;i<=n;i++){
		   for(int j=1;j<=3;j++){
		   	    cin>>a[i][j];
		    }	
		}
		for(int i=1;i<=n;i++){
		   for(int j=1;j<=3;j++){
		   	    zs=max(a[i][j],a[i][j+1]);
		   	    ans+=zs;
		    }	
		}
		cout<<ans<<endl;
	}
	return 0;
}
