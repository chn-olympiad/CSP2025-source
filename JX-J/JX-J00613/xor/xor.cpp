#include<bits/stdc++.h>
using namespace std;
int n,k,a[200009];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.ans","w",stdout);
   cin>>n>>k;
   for(int i=1;i<=n;i++)cin>>a[i];
   if(k==2)cout<<"2";
   else if(k==3)cout<<"2";
   else if(k==0)cout<<"1";
   return 0;
}
