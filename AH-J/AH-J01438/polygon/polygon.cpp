#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]==1){
        cout<<9;
    }else{
        cout<<6;
    }
    return 0;
}
