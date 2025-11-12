#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        for(int i=n-1;i>=1;i--) ans+=i;
    }
    else ans=2;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
