#include<bits/stdc++.h>
using namespace std;
long long a[5003],sum=0,ma=-1;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        ma=max(ma,a[i]);
    }
    if(sum>2*ms)cout<<1;
    else cout<<0;
    return 0;
}
