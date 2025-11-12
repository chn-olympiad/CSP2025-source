#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin)
    freopen("polygon.out","w",stdout)
    int n;
    cin>>n;
    int a[n+1];
   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   for(int i=2,i<n;i++){
       if(a[i]+a[i+1]>a[i-1]){
	    s++;
	}
   }
    return 0;
}
