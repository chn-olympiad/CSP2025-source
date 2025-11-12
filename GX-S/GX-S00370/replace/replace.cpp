#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005],x,y;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    long long sum,m;
    while(q--)
    {
        sum=0;
        cin>>x>>y;
        string c,d;
        for(int i=1;i<=n;i++)
        {
            m=x.find(a[i]);
            if(m<=x.size())
            {
                c=x.substr(0,m);
                d=x.substr(m+a[i].size(),x.size()-1);
                if(c+b[i]==y||b[i]+d==y||c+b[i]+d==y||b[i]==y)sum++;
            }

        }
        cout<<sum<<endl;
    }

    return 0;
}
