#include<bits/stdc++.h>
using namespace std;
int n,a[5],sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    if(sum>a[3]*2){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}
