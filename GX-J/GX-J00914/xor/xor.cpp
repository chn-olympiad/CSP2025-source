#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    //cout<<(n^k);
    int a[1919810];
    for(int i=0;i<n;i++)cin>>a[i];
    long long ans=0;
    for(int i=0;i<n;i++)if(a[i]==k)ans++;
    for(int i=0;i<n;i++){
        int r=i;
        int x=(a[r]^a[r-1]);
        while(r<n)
    {
        if(x==k)
        {
            ans++;
            x=0;
            r+=1;
        }
        else{
            r+=1;
            x+=(a[r-1]^a[r]);
        }
    }
    }
    cout<<ans;
    return 0;
}
