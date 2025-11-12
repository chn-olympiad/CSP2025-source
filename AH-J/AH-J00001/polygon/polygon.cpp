#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ws,zs;
bool cmp(int a,int b){
     return a>b;
}
int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ws=1;
      for(int i=0;i<n;i++){
            int s=0;
        for(int j=0;j<ws;j++){
            s+=a[i]+a[i+j];
        }
     for(int k=0;k<n;k++){
        if(s>a[k])zs++;
     }
     zs-=ws+1;
      }
     cout<<zs;
return 0;
}
