#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[5010];
ll ans=0,cant=0;
ll zh(int a,int b){
   ll res=1;
   for(int i=1;i<=a;i++){
      res=res*i; 
   }
   for(int j=a-1;j>=a-b+1;j--){
         res=res/j;
     }
   return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
       ans+=zh(n,i);
    }
    ans=ans%998244353;
    ans=ans-cant;
    if(ans<0){
		ans=ans+998244353;
	}
	cout<<ans/2;
    return 0;
}
