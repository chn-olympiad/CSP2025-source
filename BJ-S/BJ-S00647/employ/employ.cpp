#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   int n;
   long long ans=1;
   cin>>n;
   while(n){
       ans*=n;
       n--;
       ans=ans%998244353;
	}
   cout<<ans;
   return 0;
}