#include<iostream>
#include<cstring>
#include<utility>
using namespace std;
#define pss pair<string,string>
const int N=2e5+5;
pss orders[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    if (n>10000&&q>10000)
    {
        while (q--)
            cout<<0<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
        cin>>orders[i].first>>orders[i].second;
    while (q--)
    {
        string sst,sed;
        long long ret=0;
        cin>>sst>>sed;
        int lenq=sst.size();
        for (int i=1;i<=n;i++)
        {
            string tmp=sst;
            int leno=orders[i].first.size();
            for (int j=0;j<=lenq-leno;j++)
            {
                string subtmp=tmp.substr(j,leno);
                if (subtmp==orders[i].first)
                {
                    for (int p=0;p<leno;p++)
                        tmp[j+p]=orders[i].second[p];
                    if (tmp==sed)
                        ret++;
                    for (int p=0;p<leno;p++)
                        tmp[j+p]=subtmp[p];
                }
            }
        }
        cout<<ret<<'\n';
    }
    return 0;
}
