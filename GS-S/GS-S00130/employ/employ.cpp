#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("employ.in","r",stdin);
     freopen("employ.out","w",stdout);
     int n,m;
     cin>>n>>m;
     if(n>m && n%m!=0){
        cout<<m<<endl;
     }
     else if(n>m && n%m==0){
        cout<<n/m<<n/m<<"0"<<n/m*2<<n/m-1<<n/m<<n/m*4<<endl;
     }
     //fclose(stdin);
     //fclose(stdout);
     return 0;
}
