#include<bits/stdc++.h>
using namespace std;
long long c[501];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m,cnt=0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(long long i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]>0)cnt++;
    }
    long long ans=cnt;
    for(long long i=n-1;i>0;i--)ans=ans*i%998244353;
    cout<<ans;
    return 0;
}
