#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    int k=0;
    cin>>n;
    char a[n];
    for(int i=0;i<=n;i++){
        cin>>a[i];
        k++;
    }cout<<k;
    return 0;
}
