#include<bits/stdc++.h>
using namespace std;
int a[500005],maxx=-1e9;
int numm;
int n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>numm;
        a[numm]++;
    }
        cout<<a[k];
    return 0;
}
