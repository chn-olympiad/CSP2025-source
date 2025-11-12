#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n<3) cout<<0;
    else
    {
        int sum=a[0]+a[1]+a[2];
        int maxx=2*max(a[0],max(a[1],a[2]));
        if(sum>maxx) cout<<1;
        else cout<<0;
    }
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
