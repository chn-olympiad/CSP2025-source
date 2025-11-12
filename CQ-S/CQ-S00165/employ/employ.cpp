/*
lg 592080 关注谢谢喵！
*/
#include<bits/stdc++.h>
#define int long long
// #define MORE_TEST
using namespace std;
const string FILE_NAME="employ";
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    #ifndef LOCAL
        freopen((FILE_NAME+".in").c_str(),"r",stdin);
        freopen((FILE_NAME+".out").c_str(),"w",stdout);
    #endif

    int T=1;
    #ifdef MORE_TEST
        cin>>T;
    #endif

    while (T--)
    {
        int n,m;
        cin>>n>>m;

        string s;
        cin>>s;

        vector<int> a(n+1);
        for (int i=1;i<=n;i++)
            cin>>a[i];

        vector<int> p(n+1);
        iota(p.begin(),p.end(),0);
        int ans=0;
        do
        {
            for (int i=1;i<=n;i++)
                cerr<<p[i]<<' ';
            cerr<<'\n';
            int cnt=0,cnt_f=0;
            for (int i=1;i<=n;i++)
            {
                if (a[p[i]]<cnt_f||s[i-1]=='0')
                {

                    cnt_f++;
                    continue;
                }
                cnt++;
                if (cnt>=m)
                {
                    ans=(ans+1)%998244353;
                    break;
                }
            }
        }while (next_permutation(p.begin()+1,p.end()));
        cout<<ans;
    }

    return 0;
}