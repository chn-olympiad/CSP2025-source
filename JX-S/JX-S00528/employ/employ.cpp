#include <bits/stdc++.h>
using namespace std;
int a[527];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,g1=0,g0=0,s0=0;
    long long da=1;
    cin>>n>>m;
    string hi;
    cin>>hi;
    for(int i=0;i<n;i++){
        if(hi[i]=='0')g0++;
        else g1++;
        cin>>a[i];
        if(a[i]==0)s0++;
    }
    if(g1<m)cout<<0;
    else if(s0==n)cout<<0;
    else{
        cout<<0;
    }
    return 0;
}
