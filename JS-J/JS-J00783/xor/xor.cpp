#include<bits/stdc++.h>
using namespace std;
    int a[500010],s[500010],i,flag=1,n,g,x,j,gz,sum;
    bool f[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>g;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    while(flag>0)
    {
        flag=0;
        i=1;
        while(i+x<=n)
        {
            gz=0;
            for(j=i;j<=x+i;j++)
            {
                if(f[j]==1)
                {
                    gz=1;
                    break;
                }
            }
            if(gz==0)
            {
                flag++;
                if((s[j-1]^s[i-1])==g)
                {
                    for(j=i;j<=x+i;j++)
                    {
                        f[j]=1;
                    }
                    sum++;
                }
                i=i+x+1;
            }
            else
            i=j+1;
        }
        x++;
    }
    cout<<sum;
    return 0;
}
