#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string a,b;
    m.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        int be=0,ed=a.size()-1;
        while(be<a.size()&&a[be]==b[be]){be++;}
        while(ed>=0&&a[ed]==b[ed]){ed--;}
        if(be>ed)
        {
            continue;
        }
        a=a.substr(be,ed-be+1);
        b=b.substr(be,ed-be+1);
        m[a+'#'+b]++;
    }
    while(q--)
    {
        cin>>a>>b;
        if(a.size()!=b.size())
        {
            cout<<0<<endl;
            continue;
        }
        int be=0,ed=a.size()-1;
        while(be<a.size()&&a[be]==b[be]){be++;}
        while(ed>=0&&a[ed]==b[ed]){ed--;}
        a=a.substr(be,ed-be+1);
        b=b.substr(be,ed-be+1);
        cout<<m[a+'#'+b]<<endl;
    }
    return 0;
}
