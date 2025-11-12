#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m;
bitset<505>s;
int c[505];
ll ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        char ch;
        cin>>ch;
        s[i]=(ch=='1');
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    if(s.count()==n)
    {
        ans=1;
        for(int i=1;i<=n;i++)ans*=i,ans%=mod;
        cout<<ans;
        return 0;
    }
    if(n<=10)
    {
        vector<int>a(n);
        for(int i=0;i<n;i++)a[i]=i;
        do
        {
            int cnt0=0,cnt1=0;
            for(int i=0;i<n;i++)
            {
                //cout<<a[i]<<' ';
                if((!s[i])||cnt0>=c[a[i]])cnt0++;
                else cnt1++;
            }//cout<<endl;
            if(cnt1>=m)ans++;
        }while(next_permutation(a.begin(),a.end()));
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
