#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
using namespace std;
#define mod 998244353
int n,m;
string s;
int c[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)
        {
            cnt++;
        }
    }
    long long ans=0,tmp=cnt;
    for(int i=n-cnt;i>=n-cnt-m+2;i--)
    {
        tmp=tmp*i%mod;
    }
    if(n-cnt>=m-1)
    {
        ans+=tmp;
    }
    tmp=1;
    for(int i=n-cnt;i>=n-cnt-m+1;i--)
    {
        //cout<<tmp<<' '<<i<<endl;
        tmp=tmp*i%mod;
    }
    if(n-cnt>=m)
    {
        ans+=tmp;
    }
    cout<<ans;
    return 0;
}
