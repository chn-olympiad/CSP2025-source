#include<bits/stdc++.h>
using namespace std;
long long n,q,l,r,l2[200010],r2[200010],sum;
string x[200010],y,z[200010],o,y2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>z[i];
        for(int j=0;j<x[i].size();j++)
        {
            if(l2[i]==0&&x[i][j]!=z[i][j]&&x[i][0]==z[i][0])
            {
                l2[i]=j;
            }
            if(x[i][j]!=z[i][j])
            {
                r2[i]=j;
            }
        }
        //cout<<l2[i]<<" "<<r2[i]<<endl;
    }
    for(int i=1;i<=q;i++)
    {
        cin>>y>>y2;
        sum=0;
        l=0;
        r=0;
        if(y.size()!=y2.size())
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<y.size();i++)
        {
            if(l==0&&y[i]!=y2[i]&&y[0]==y2[0])
            {
                l=i;
            }
            if(y[i]!=y2[i])
            {
                r=i;
            }
        }
        //cout<<l<<" "<<r<<endl;
        for(int j=1;j<=n;j++)
        {
            int e=0;
            if(r2[j]-l2[j]==r-l)
            {
                for(int k=0;k<=r-l;k++)
                {
                    if(x[j][k+l2[j]]!=y[k+l]||z[j][k+l2[j]]!=y2[k+l])
                    {
                        e=1;
                        break;
                    }
                }
            }
            else continue;

            if(e==0&&l>=l2[j])
            {

                for(int k=0;k<x[j].size();k++)
                {
                    if(x[j][k]!=y[k+l-l2[j]])
                    {
                        e=1;
                        break;
                    }
                }
            }
            else continue;
            if(e==0) sum++;
        }
        cout<<sum<<endl;
    }
}