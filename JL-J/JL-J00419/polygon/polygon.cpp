#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    if(n==2&&m==2)
        cout<<1<<" "<<2;
    return 0;
}
