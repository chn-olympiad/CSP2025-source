#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,l,cnt0,cnt1=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>l;
        if(l==1) cnt1++;
        else cnt0++;
    }
    if(k>=2) cout<<'0';
    else{
        if(k==0) cout<<cnt0;
        else cout<<cnt1;
    }
    return 0;
}
