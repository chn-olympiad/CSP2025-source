#include <bits/stdc++.h>
using namespace std;
int n,q;
int pos1,pos2;
string s[100010][2];
string t2,t1;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>s[i][0]>>s[i][1];
    while(q--)
    {
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<0<<"\n";
            continue;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            pos1=t1.find(s[i][0]);
            pos2=t2.find(s[i][1]);
            while(pos1!=string::npos&&pos2!=string::npos)
            {
                if(pos1==pos2)
                {
                    ans++;
                    break;
                }
                else if(pos1<pos2)
                    pos1=t1.find(s[i][0],pos1);
                else
                    pos2=t2.find(s[i][1],pos2);
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
