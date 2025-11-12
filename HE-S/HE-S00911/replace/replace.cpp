#include <iostream>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int m,n,k=0;
    string a,b,c,d;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c>>d;
        for(int j=0;j<min(c.length(),d.length());j++)
        {
            if(c[j]==d[j])
            {
                k++;
            }
        }
        if(k==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<2<<endl;
        }
        k=0;
    }

}
