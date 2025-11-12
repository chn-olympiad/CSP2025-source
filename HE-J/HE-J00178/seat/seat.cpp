#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){	
int n,m,a[100],ans,modn,modm;//modm:行数 modn:列数 
cin>>n>>m;for(int i=0;i<n*m;i++)cin>>a[i];
int t=a[0];
sort(a,a+n*m,cmp);
for(int i=0;i<n*m;i++)if(a[i]==t)ans=i+1;
modm=ans%m;
   if(modm==0)
      modm=n,modn=ans/n;
   else{
   modn=ans/n+1;
   }
   if(modn%2==0)
      cout<<modn<<' '<<n-modm;
   else{
      cout<<modn<<' '<<modm;
	  }
return 0;
}/*
2 2
3 2 1 4
4 3 2 1
ans=2 modm=0 modn=1 2 1
*/
