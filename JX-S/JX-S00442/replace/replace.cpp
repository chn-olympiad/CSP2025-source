#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
int len[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],len[i]=s1[i].size();
    while(q--)
    {
        string t1,t2;
        int ans=0;
        cin>>t1>>t2;
        for(int i=0;i<t1.size();i++)
        {
            for(int i=1;i<=n;i++)
                if(t1[i]==s1[i][0])
                {
                    string x=t1.substr(i,len[i]);
                    if(x==s1[i])
                    {
                        string y=t2.substr(i,len[i]);
                        if(y==t2) ans++;
                    }
                }
        }
        cout<<ans<<endl;
    }
    return 0;
}
