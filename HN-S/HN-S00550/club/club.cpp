#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[2005][5];
	cin>>t;
    while(t--){
    	cin>>n;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<3;j++) cin>>a[i][j];
		}
    	if(n==2){
    		int a1=0,a2=0,ma=-1,lw,nd;
    		ma=max(a[0][0]+a[1][1],a[0][0]+a[1][2]);
    		ma=max(ma,a[0][1]+a[1][0]);
    		ma=max(ma,a[0][1]+a[1][2]);
    		ma=max(ma,a[0][2]+a[1][0]);
    		ma=max(ma,a[0][2]+a[1][1]);
    		cout<<ma<<endl;
		}
		
	}
	return 0;
}
