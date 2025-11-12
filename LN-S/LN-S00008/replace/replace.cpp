#include<bits/stdc++.h>
using namespace std;
int n,q;
int yx[10000010];
string a[200010],b[200010];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        int x=a.find('b');
        int y=b.find('b');
        int z=x-y+5e6;
        yx[z]++;
    }
    for(int i=1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size())
        {
            cout<<0<<"\n";
            continue;
        }
        int x=t1.find('b');
        int y=t2.find('b');
        int z=y-x+5e6;
        cout<<yx[z]<<"\n";
    }
    return 0;
}
