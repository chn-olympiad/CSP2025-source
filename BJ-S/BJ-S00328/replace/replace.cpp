#include<bits/stdc++.h>
using namespace std;
string s1[300000],s2[300000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >>q;
    for (int i=1;i<=n;i++)cin >> s1[i] >> s2[i];
    while (q--)
    {
        string t1,t2;
        cin >>t1 >>t2;
        if (t1.size()!=t2.size())
        {
            cout << "0\n";
            continue;
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int x=t1.find(s1[i]);
            if (x==-1)
            {
                //cout << "3: i=" << i << "\n";
                continue;
            }
            int size1=t1.size(),size2=s1[i].size();
            bool flag=1;
            for (int j=0;j<size1;j++)
            {
                if (j>=x && j<=x+size2-1)
                {
                    if (s2[i][j-x]!=t2[j])
                    {
                        flag=0;
                        //cout << "1: j=" <<j <<"\n";
                        break;
                    }
                }
                else
                {
                    if (t1[j]!=t2[j])
                    {
                        flag=0;
                        //cout << "2: j=" << j <<"\n";
                        break;
                    }
                }
            }
            //cout << flag << "\n";
            ans+=flag;
        }
        cout << ans <<"\n";
    }
    return 0;
}
