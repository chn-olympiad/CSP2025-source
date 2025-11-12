#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,o,a1[100001],a2[100001],a3[100001],x,y,z,a,b,c,m;
long long ans[6];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    for(o=1;o<=t;o++)
    {
        a=0;
        b=0;
        c=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            if((x>=y)&&(x>=z))
            {
                a++;
                ans[o]+=x;
                a1[a]=x-max(y,z);
            }
            else
            {
                if((y>=x)&&(y>=z))
                {
                    b++;
                    ans[o]+=y;
                    a2[b]=y-max(x,z);
                }
                else
                {
                    c++;
                    ans[o]+=z;
                    a3[c]=z-max(x,y);
                }
            }
        }
        if(a>n/2)
        {
            m=a-n/2;
            sort(a1+1,a1+a);
            for(j=1;j<=m;j++)
            {
                ans[o]-=a1[j];
            }
        }
        else
        {
            if(b>n/2)
            {
                m=b-n/2;
                sort(a2+1,a2+b);
                for(j=1;j<=m;j++)
                {
                    ans[o]-=a2[j];
                }
            }
            if(c>n/2)
            {
                m=c-n/2;
                sort(a3+1,a3+c);
                for(j=1;j<=m;j++)
                {
                    ans[o]-=a3[j];
                }
            }
        }
    }
    for(o=1;o<=t;o++)
    {
        cout<<ans[o]<<endl;
    }


    return 0;
}










