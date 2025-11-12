#include<bits/stdc++.h>
using namespace std;
string a[200010],b[200010],c,d,x;
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    while(q--)
    {
        int cnt=0;
        cin>>c>>d;
        if(c.size()!=d.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            x="";
            if(c.find(a[i])==d.find(b[i]) && c.find(a[i])<=5000001 && d.find(b[i])<=5000001)
            {
                for(int j=0;j<c.find(a[i]);j++)
                    x+=c[j];
                x+=b[i];
                for(int j=c.find(a[i])+a[i].size();j<c.size();j++)
                    x+=c[j];
                if(x==d)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
