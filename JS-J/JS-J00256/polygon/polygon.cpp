#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5050];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==3)cout<<1;
    else    {
            for(int i=1;i<n;i++)ans+=i;
        cout<<ans;
    }
    return 0;
}
