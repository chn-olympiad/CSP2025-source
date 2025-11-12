#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,st[510],an[510];
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    string str;
    int zeronum=0;
    cin >> str;
    for(int i=0;i<n;i++)
    {
        cin >> an[i];
        if(an[i]==0) zeronum++;
    }
    __int128 ans=n,ans2=n-1;
    for(long long i=n-1;i>=m;i--) ans=(ans*i);
    cout << (long long)(ans%998244353)<< endl;
    return 0;
}
