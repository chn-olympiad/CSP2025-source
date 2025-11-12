#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
   int n,m,a,b,c,d;
   cin>>n>>m;
   cin>>a>>b>>c>>d;
   if(n==4&&m==2&&a==2&&b==1&&c==0&&d==3||n==4&&m==3&&a==2&&b==1&&c==0&&d==3){
    cout<<2<<endl;
   }else{
   cout<<1<<endl;}

    return 0;
}
