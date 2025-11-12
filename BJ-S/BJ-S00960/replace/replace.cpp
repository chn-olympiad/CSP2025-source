#include<bits/stdc++.h>
using namespace std;
int n,q;

struct stpair{
    string a,b;
} s[1005];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].b;
    }
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        for(int i=0;i<t1.length();i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i+s[j].a.length()>t1.length()) continue;
                int len;
                len=t1.length()-i-s[j].a.length();
                int start;
                start=i+s[j].a.length();
                if(t1.substr(i,s[j].a.length())==s[j].a&&(t1.substr(0,i)+s[j].b+t1.substr(start,len))==t2) ans++;
                //cout<<t1.substr(0,i)<<" "<<s[j].b<<" "<<t1.substr(start,len)<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
