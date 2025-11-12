#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],s[300010],d[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int k=0;k<t;k++)
    {
        long long w=0;
        fill(a+1,a+n+2,0);
        fill(b+1,b+n+2,0);
        fill(c+1,c+n+2,0);
        fill(d+1,d+n+2,0);
        fill(s+1,s+3*n+8,0);
        //for(int i=1;i<=n+2;i++)
        //{
          //  d[i]=0;
        //}
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];

        }
        int aq=0,bq=0,cq=0,p=1;
        int zd=max(aq,bq);
        zd=max(zd,cq);
        int qq=n/2-zd;
        while((zd<n/2)&&(p))
        {
            int zd=max(aq,bq);
            zd=max(zd,cq);
            int qq=n/2-zd+1;
            fill(s+1,s+n*3+8,0);
            for(int i=1;i<=n;i++)
            {
                if(d[i])
                {
                    continue;
                }
                s[i*3-2]=a[i];
                s[i*3-1]=b[i];
                s[i*3]=c[i];
            }
            sort(s+1,s+n*3+1);
            for(int i=1;i<=n;i++)
            {
                if(d[i])
                {
                    continue;
                }
                int bj=max(a[i],b[i]);
                bj=max(bj,c[i]);
                if(bj>=s[qq])
                {
                    int js=-1;
                    w+=bj;
                    d[i]=1;
                    if(a[i]>=s[qq])
                    {
                        js++;
                        if(a[i]==bj)
                        {
                            aq++;
                        }
                    }
                    if(b[i]>=s[qq])
                    {
                        js++;
                        if(b[i]==bj)
                        {
                            bq++;
                        }
                    }
                    if(c[i]>=s[qq])
                    {
                        js++;
                        if(c[i]==bj)
                        {
                            cq++;
                        }
                    }
                    qq+=js;
                }
            }
            zd=max(aq,bq);
            zd=max(zd,cq);
            p=0;
        }
        cout<<w<<endl;
    }
    return 0;//Ren5Jie4Di4Ling5%
}
