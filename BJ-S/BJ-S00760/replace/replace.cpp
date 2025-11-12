#include <iostream>
#include <cstring>
using namespace std;
int n,q,x;
string s[200005][2];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
        int ll=s[i][1].size();
        x=max(ll,x);
    }
    for(i=1;i<=q;i++)
    {
        string r1,r2;
        int as=0;
        cin>>r1>>r2;
        if(r1.size()!=r2.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int l=1;l<=x;l++)
        {
            for(int j=0;j+l-1<r1.size();j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(s[k][1].size()!=l)continue;
                    int f=1;
                    for(int m=j;m<=j+l-1;m++)
                    {
                        if(s[k][1][m-j+1]!=r1[m])
                        {
                            f=0;break;
                        }
                    }
                    if(f==1)
                    {
                        int ff=1;
                        for(int m=j;m<=j+l-1;m++)
                        {
                            if(s[k][2][m-j+1]!=r2[m])
                            {
                                ff=0;break;
                            }
                        }
                        if(ff==1)as++;
                    }
                }
            }
        }
        cout<<as<<endl;
    }
}
