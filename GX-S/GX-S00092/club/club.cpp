#include<bits/stdc++.h>;
using namespace std;
long long int t,n,bm[3],myd;
long long int a,b,c,sum=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
	for(int i=1;i<=t;++i){
	    cin>>n;
	   for(int j=1;j<=3;++j){
       int a[n][3];
       cin>>a[j][i];
       bm[j-1]=a[j][i];
	   }
	   myd=max(bm[1],bm[2],bm[3]);
	   sum+=myd;
	}
	   cout<<sum<<endl;
	return 0;
}
