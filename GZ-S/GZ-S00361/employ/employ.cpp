//GZ-S00361 毕节东辰实验学校 罗圣喻
#include <bits/stdc++.h>
using namespace std;
long long modd=998244353;
int n,m;
string s;
int a[100005],num[100005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    int x=n-num[0];
    if(x<m)
    {
        cout<<0;
        return 0;
    }
    long long ans=1;
        for(int i=n;i>=1;i--)
        {
            ans*=i;
            ans%=modd;
        }
    cout<<ans;
    return 0;
}
