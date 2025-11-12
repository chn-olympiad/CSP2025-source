#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N],t[N];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>s[i]>>t[i];
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string tmp=t1;
            int rsz=s[i].size();
            for(int j=0;j+rsz-1<t1.size();j++)
            {
                tmp=t1;
                if(tmp.substr(j,rsz)==s[i])
                {
                    tmp=tmp.substr(0,j)+t[i]+tmp.substr(j+rsz);
                }
                if(tmp==t2)
                {
                    ++ans;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}