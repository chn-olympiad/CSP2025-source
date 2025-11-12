#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int main(){
    freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    int sum=0,max_1=0;
    if(n==3){
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(max_1<=a[i]) max_1 = a[i];

    }
    if(sum > 2*max_1) cout<<"1";
    else cout<< "0" ;
    }else{
        cout<<"10";
    }

    return 0;
}


