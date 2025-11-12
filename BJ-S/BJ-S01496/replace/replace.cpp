#include<iostream>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int ans[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;i++)
    {
        string a,b,t=s1[i];
        cin>>a>>b;
        while(1)
        {
            int pos=-1;
            here:
            pos=s1[i].find(a,pos+1);
            if(pos==-1||a.size()+pos>t.size()) break;
            else
            {
                t.replace(pos,b.size(),b);
                if(t==s2[i])
                {
                    cout<<a;
                    ans[i]++;
                }
                goto here;
            }
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i];
    return 0;
}
