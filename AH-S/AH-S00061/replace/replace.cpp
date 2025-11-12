#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string sy[200002],st[200002],t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>sy[i]>>st[i];
    for(int i=1;i<=q;i++)
    {
        ans=0;
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<t1.size();j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(t1.size()<sy[k].size())continue;
                if(t1.substr(j,sy[k].size())==sy[k]&&t2.substr(j,st[k].size())==st[k]&&t1.substr(0,j)==t2.substr(0,j)&&t1.substr(j+sy[k].size(),t1.size()-(j+sy[k].size()))==t2.substr(j+st[k].size(),t2.size()-(j+st[k].size())))ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
