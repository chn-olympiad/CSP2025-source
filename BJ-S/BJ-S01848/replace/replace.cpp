#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,q;
string s1[N],s2[N],a,b;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
    while(q--)
    {
        int ans=0;
        cin>>a>>b;
        for(int k=1;k<=n;k++)
        {
            for(int i=0;i<a.size();i++)
            {
                if(a[i]==s1[k][0])
                {
                    bool ib=1;
                    string a2=a;
                    for(int j=i;j<=i+s1[k].size()-1;j++)
                    {
                        if(a2[j]!=s1[k][j-i])
                        {
                            ib=0;
                            break;
                        }
                        a2[j]=s2[k][j-i];
                        if(a2[j]!=b[j])
                        {
                            ib=0;
                            break;
                        }
                    }
                    if(ib==1&&a2==b)ans++;

                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
