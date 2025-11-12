#include<bits/stdc++.h>
using namespace std;
int k,n,s[5010];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    k=3*n;
    cout<<k;
    return 0;
}
