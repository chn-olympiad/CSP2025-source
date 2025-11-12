/*
lg 592080 关注谢谢喵！
17:58 开始写题
*/
#include<bits/stdc++.h>
#define int long long
// #define MORE_TEST
using namespace std;
const string FILE_NAME="replace";
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
        int n,q;
        cin>>n>>q;

        vector<pair<string,string>> a(n+1);
        for (int i=1;i<=n;i++)
            cin>>a[i].first>>a[i].second;

        while (q--)
        {
            string x,y;
            cin>>x>>y;
            int cnt=0,siz=x.size();
            for (int i=0;i<siz;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    bool ok=1;
                    if (i+a[j].first.size()-1>=siz)
                        continue;
                    for (int k=0;k<a[j].first.size();k++)
                        if (a[j].first[k]!=x[i+k])
                        {
                            ok=0;
                            break;
                        }
                    if (ok)
                    {
                        string tx(x);
                        for (int k=0;k<a[j].first.size();k++)
                            tx[i+k]=a[j].second[k];
                        if (tx==y)
                            cnt++;
                    }
                }
            }
            cout<<cnt<<'\n';
        }
    }

    return 0;
}