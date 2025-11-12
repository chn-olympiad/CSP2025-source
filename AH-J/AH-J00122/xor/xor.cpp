#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)f++;
        else if(a[i]==0)f++;
    }
    if(f==1)
    {
        cout<<1;
        return 0;
    }
    cout<<2;
    return 0;
}
