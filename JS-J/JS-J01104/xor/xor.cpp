/*
CSP-J 2025 T3 UnFormal
Author: DFLJ
"AC This Question,You Will Won!"
UPD: Got 60 pts at 09:46
AC Time: 11:00
*/
#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        s[i]=(s[i-1]^a[i]);
        //cout<<s[]
        //if(a[i]==k) cnt++;
    }
    int las=0;
    long long ans=0;
    map<int,int> mp;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==k||(s[i]^s[las])==k)
        {
            ans++;
            las=i;
            mp.clear();
            //cout<<i<<"  ";
            continue;
        }
        int d=(k^(s[i]^s[las]));
        if(mp[d])
        {
            //cout<<i<<"-"<<las<<"-"<<d<<"-"<<*st.find(d)<<" ";
            ans++;
            las=i;
            mp.clear();
        }
        else
        {
            mp[(s[i]^s[las])]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}