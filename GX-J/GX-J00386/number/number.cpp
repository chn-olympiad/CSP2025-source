#include<bits/stdc++.h>
using namespace std;
int n,j;
int a[10001];
int main(){
     freopen("number.in","r",stdin);
     freopen("number.out","w",stdout);
     cin>>n;
     for(int i=0;i<n;i++){
           cin>>j;
           if(j>=0&&j<=0){
                a[i]=j;
           }
     }
     for(int i=n;i>=0;i--){
           cout<<a[i];
     }
     return 0;
}
