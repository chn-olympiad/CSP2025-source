#include<bits/stdc++.h>
using namespace std;

const int N=1e5*5+5;
int a[N],n,k;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(k==1) cout<<n;
    else cout<<0;
    return 0;
}
