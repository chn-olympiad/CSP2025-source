#include<bits/stdc++.h>
#define N 1
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
int n,x,y,z;
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if(n==3)
    {
        cin>>x>>y>>z;
        if(x+y+z>max(x,max(y,z))*2)  cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    cout<<n*(n-1)/2-3;
}
