#include <bits/stdc++.h>
using namespace std;
string c[200004],d[200004];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    long long n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i]>>d[i];
    }
    for(int i=1;i<=q;i++)
    {
        long long x=0;
        string a,b,e;
        cin>>a>>b;
        e=a;
        for(int j=1;j<=n;j++)
        {
            a=e;
            int r=0,f,g;
            if(a.find(c[j]))
            {
                if(d[j]==b)
                {
                    x++;
                }
                for(int k=0;k<a.size();k++)
                {
                    if(r==c[j].size()-1)
                    {
                        g=k;
                        break;
                    }
                    if(a[k]==c[j][r])
                    {
                        r++;
                        if(r==1)
                        {
                            f=k;
                        }
                    }
                    else
                    {
                        f=-1;
                        r=0;
                    }

                }
                int h=0;
                for(int k=f;k<=g;k++)
                {
                    a[k]=d[j][h];
                    h++;
                }
                if(a==b)
                {
                    x++;
                }
            }
        }
        cout<<x<<endl;
    }
    return 0;
}
