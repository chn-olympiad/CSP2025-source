#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][2],c1,c2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int i,j,k,cnt,ans;
    cin>>n>>q;
    for(i=1; i<=n; i++)
        cin>>s[i][0]>>s[i][1];
    while(q--)
    {
        cin>>c1>>c2;
        ans=0;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<=(int)c1.size()-(int)s[i][0].size(); j++)
            {
                cnt=1;
                for(k=j; k<j+s[i][0].size(); k++)
                {
                    if(c1[k]!=s[i][0][k] || c2[k]!=s[i][1][k])
                    {
                        cnt=0;
                        break;
                    }
                }
                if(cnt)
                    ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
