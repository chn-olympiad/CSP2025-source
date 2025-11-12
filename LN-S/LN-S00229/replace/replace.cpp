#include<bits/stdc++.h>
const int N=2e5+5;
using namespace std;
int n,q,ans;
string s1[N],s2[N],t1,t2;
map<string,string> mp;
int main(void)
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
        mp[s1[i]]=s2[i];
    }
    for(int j=1;j<=q;j++)
    {
        cin>>t1>>t2;
        ans=0;
        int len=t1.size();
        for(int i=0;i<len;i++)
        {
            for(int r=1;r+i<=len;r++)
            {
                string na=t1.substr(i,r);
                string nb=t2.substr(i,r);
                    string n1,n2,n3,n4;
                    n1=t1.substr(0,i);
                    n2=t2.substr(0,i);
                    if(n1!=n2)
                        continue;
                    n3=t1.substr(i+r-1);
                    n4=t2.substr(i+r-1);
                    if(n3!=n4)
                        continue;
                if(mp.count(na))
                {
                    if(mp[na]==nb)
                        ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
