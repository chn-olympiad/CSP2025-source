#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e5+10;
int n,k,t;
int a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            t++;
        }
        cout<<t/2;
    }
    return 0;
}
