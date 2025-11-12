#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10005]={0};
    for(int i=0;i<n;++i){
       cin>>a[i];
    }
    if(m%2==0){
      cout<<m;
    }else{
     cout<<"0";
    }
    return 0;
}
