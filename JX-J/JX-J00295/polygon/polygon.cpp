#include<bits/stdc++.h>

using namespace std;
const int m=998244353;
int a[5005],s[5005];
int jc[5005];
int n,k,maxn=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=2)cout<<0;
    else{
        if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
    }
    return 0;
}


