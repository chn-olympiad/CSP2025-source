#include <bits/stdc++.h>

using namespace std;
const int N = 2*1e5+11;
int n,q;
string a[N],b[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i = 1;i<=q;i++)
    {
        int ans = 0;
        string x,y;
        cin >> x >> y;
        if(x.size()!=y.size()) {cout << 0 << endl;continue;}
        for(int i = 0;i<x.size();i++)
        {
            for(int j = i;j<x.size();j++)
            {
                string nx = "",ny = "",nx1 = "",ny1 = "",nx2 = "",ny2 = "";
                for(int k = i;k<=j;k++)
                {
                    nx += x[k];
                    ny += y[k];
                }
                for(int k = 0;k<i;k++)
                {
                    nx1 += x[k];
                    ny1 += y[k];
                }
                if(nx1!=ny1) continue;
                for(int k = j+1;k<x.size();k++)
                {
                    nx2 += x[k];
                    ny2 += y[k];
                }
                if(nx2!=ny2) continue;
                for(int k = 1;k<=n;k++)
                {
                    if(nx == a[k]&&ny == b[k]) ans++;

                }

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
