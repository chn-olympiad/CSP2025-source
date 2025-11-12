#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        mp[a]=b;
        mp[b]=a;
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        if(q==1||(t1.size()<=200&&t2.size()<=200))
        {
            int sl=t1.size(),ans=0;
            for(int i=0;i<sl;i++)
            {
                for(int j=i;j<sl;j++)
                {
                    string k=t1.substr(i,j-i+1);
                    if(mp.count(k)!=0)
                    {
                        string x,z;
                        if(i==0)
                            x="";
                        else
                            x=t1.substr(0,i);
                        if(j==sl-1)
                            z="";
                        else
                            z=t1.substr(j+1,sl-(j+1));
                        string xin=x+mp[k]+z;
                        if(xin==t2)
                            ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
        else
            cout<<0<<"\n";
    }
    return 0;
}