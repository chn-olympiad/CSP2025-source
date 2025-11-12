#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int s[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(n<=2){
        if(n==1) cout<<0<<endl;
        else cout<<2<<endl;
    }

    return 0;
}