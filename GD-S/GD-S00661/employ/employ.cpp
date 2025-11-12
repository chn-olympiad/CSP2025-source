#include<bits/stdc++.h>
using namespace std;
int n,k,c[15],a[15],ans;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    if(n>12)
    {
        cout<<0;
        return 0;
    }
    cin>>s;
    s="$"+s;
    for(int i=1;i<=n;i++)cin>>c[i];
    iota(a+1,a+n+1,1);
    do
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(s[i]=='1'&&i-cnt-1<c[a[i]])
                cnt++;
        ans+=(cnt>=k);
        if(ans>=998244353)ans-=998244353;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}
/*
g++ employ.cpp -o employ
employ.exe

// freopen("employ.in","r",stdin);
// freopen("employ.out","w",stdout);
// freopen("employ.in","r",stdin);
// freopen("employ.out","w",stdout);
// freopen("employ.in","r",stdin);
// freopen("employ.out","w",stdout);
// freopen("employ.in","r",stdin);
// freopen("employ.out","w",stdout);
// freopen("employ.in","r",stdin);
// freopen("employ.out","w",stdout);
*/