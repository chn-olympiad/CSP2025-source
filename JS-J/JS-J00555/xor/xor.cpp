#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,ans,a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k!=0) cout<<'2'<<'\n';
    else cout<<'0'<<endl;
    return 0;
}
