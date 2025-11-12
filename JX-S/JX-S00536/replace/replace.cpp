#include <bits/stdc++.h>
using namespace std;
#define  int long long
int n,q;
string s[200001][2],t0,t1;
void pre()
{
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    if(true)
{
        freopen("replace.in","r",stdin);
        freopen("replace.out","w",stdout);
    }
}
void clear()
{


}
void readmeta()
{
    cin>>n>>q;
    for(int i = 1; i<=n; i++)
    {
        cin>>s[i][0]>>s[i][1];
    }
}
void solve()
{
    for(int i = 1; i<=q; i++)
    {
        cin>>t0>>t1;
        int cnt = 0;

        for(int j= 1; j<=n; j++)
        {
            for(int k = 0; k+s[j][0].length()<=t0.length(); k++)
                if(t0.substr(k,s[j][0].length())==s[j][0])
                {
                    if(t0.substr(0,k)+s[j][1]+t0.substr(k+s[j][0].length())==t1){
                            ++cnt;break;}

                }
        }
        cout<<cnt<<endl;
    }
}
signed main()
{
    pre();
    int t = 1;
//    cin>>t;
    while(t--)
    {
        clear();
        readmeta();
        solve();
    }
    return 0;
}

