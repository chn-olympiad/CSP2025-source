#include<bits/stdc++.h>
using namespace std;
int n,a[100];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<n*(n-1)*(n-2)/6<<endl;
    return 0;
}//12points
