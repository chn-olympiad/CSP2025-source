#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<pow(n-2,2);
    return 0;
}
