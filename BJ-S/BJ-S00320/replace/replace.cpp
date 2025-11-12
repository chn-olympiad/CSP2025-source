#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long n,q,l,c[200005],ans;
string a[200005],b[200005],x,y,z;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
        c[i]=a[i].size();
    }
    for(int t=1;t<=q;++t)
    {
        ans=0;
        cin>>x>>y;
        l=x.size();
        if(q==1 || n*q<=1000)
        {
            for(int k=1;k<=n;++k)
            {
                z=x;
                for(int i=0;i<l;++i)
                {
                    if(z[i]==a[k][0])
                    {
                        for(int j=0;j<c[k] && i<l;++i,++j)
                        {
                            if(z[i]!=a[k][j])
                            {
                                z=x;
                                --i;
                                break;
                            }
                            z[i]=b[k][j];
                        }
                    }
                    if(z==y)
                    {
                        z=x;
                        ++ans;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
