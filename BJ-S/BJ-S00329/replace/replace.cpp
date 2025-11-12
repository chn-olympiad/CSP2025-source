#include<bits/stdc++.h>
using namespace std;
string chk1[200010],chk2[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>chk1[i]>>chk2[i];
    while(q--)
    {
        string t1,t2;
        int ans=0;
        cin>>t1>>t2;
        string tt=t1;
        if(t1.size()!=t2.size())
        {
            cout<<"0\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(t1.find(chk1[i])!=-1)
            {
                int pos=t1.find(chk1[i]),len=chk1[i].size();
                for(int j=pos;j<pos+len;j++)tt[j]=chk2[i][j-pos];
                if(tt==t2)ans++;
            }
            tt=t1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}