#include<bits/stdc++.h>
using namespace std;
int n,q;
unordered_map<string,string>mp;
bool flg[5000050];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    mp.clear();
    for(int i = 1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    while(q--)
    {
        string a,b,ca,ak,bk;
        int ans = 0,la,lb;
        cin>>a>>b;
        la = a.length(),lb = b.length();
        if(la!=lb)
        {
            cout<<"0\n";
            continue;
        }
        a = " " + a,b = " " + b;
        memset(flg,0,sizeof(flg));
        flg[0] = flg[la+1] = 1;
        for(int i = 1;i<=la;i++)if(a[i]==b[i])flg[i]=flg[i-1];
        for(int i = la;i>=1;i--)
            if(flg[i])break;
            else if(a[i]==b[i])flg[i]=flg[i+1];
        for(int i = 1;i<=la;i++)
            for(int j = 1;i+j-1<=la;j++)
            {
                ak = a.substr(i,j);
                bk = b.substr(i,j);
                if((!flg[i-1])||(!flg[i+j]))continue;
                if(mp.find(ak)==mp.end())continue;
                if(mp[ak]==bk)ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}