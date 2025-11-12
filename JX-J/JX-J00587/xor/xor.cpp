#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5*10e5+10;
int a[N];
long long ans;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];

    for(int i=1;i<=n;i++)
        if(a[i]==m)  ans++;

    cout<<ans<<endl;
    return 0;
}
