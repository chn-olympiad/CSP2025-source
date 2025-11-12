#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int a,b;
    cin>>a>>b;
    map<string,string> p;
    for(int i=0;i<a;i++)
    {
        string x,y;
        cin>>x>>y;
        p[x]=y;
    }
    for(int i=0;i<b;i++)
    {
        string x,y;
        cin>>x>>y;
        int sum=0;
        for(int j=1;j<=x.size();j++)
        {
            for(int ii=0;ii<x.size()-j+1;ii++)
            {
                if(p[x.substr(ii,j)]!="")
                {
                    string t=x.substr(0,ii);
                    t=t+p[x.substr(ii,j)];
                    t=t+x.substr(ii+j,x.size()-ii-j+1);
                    if(t==y)
                        sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
