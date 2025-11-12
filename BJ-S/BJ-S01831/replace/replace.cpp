#include<bits/stdc++.h>
using namespace std;

string s1[200005],s2[200005];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<=n;i++)
        cin >> s1[i] >> s2[i];
    while (q--)
    {
        int sum=0;
        string st,en;
        cin >> st >> en;
        if (st.size()!=en.size())
        {
            cout << 0 << endl;
            continue;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<st.size()-s1[i].size()+1;j++)
            {
                //cout << "&&&" << j << " " << st.size() << " " << s1[i].size() << endl;
                bool box=true;
                string ss=st;
                for (int k=j;k<=j+s1[i].size()-1;k++)
                {
                    if (st[k]!=s1[i][k-j])
                    {
                        box=false;
                        break;
                    }
                    ss[k]=s2[i][k-j];
                }
                if (box && ss==en) sum++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
