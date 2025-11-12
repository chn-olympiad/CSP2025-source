#include<bits/stdc++.h>
using namespace std;
struct person
{
    int q;
    int w;
    int e;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int sum=0;
        int n;
        cin>>n;
        int mid = n/2;
        int ch[4];
        for (int i=1;i<=3;i++)
        {
            ch[i]=0;
        }
        person a[n+1];
        int maxx[n+1];
        int maxxplace[n+1];
        int sec[n+1];
        int secplace[n+1];
        int lm[n+1];
        int lr[n+1];
        int mr[n+1];
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].q;
            cin>>a[i].w;
            cin>>a[i].e;
            lm[i]=abs(a[i].q-a[i].w);
            lr[i]=abs(a[i].q-a[i].e);
            mr[i]=abs(a[i].e-a[i].w);


        }
        for (int i=1;i<=n;i++)
        {
            if(a[i].q>a[i].w&&a[i].q>a[i].e)
            {
                maxx[i]=a[i].q;
                maxxplace[i]=1;
                if(a[i].w>=a[i].e)
                {
                    sec[i]=a[i].w;
                    secplace[i]=2;
                }
                else{
                    sec[i]=a[i].e;
                    secplace[i]=3;
                }
            }
            if(a[i].w>a[i].q&&a[i].w>a[i].e)
            {
                maxx[i]=a[i].w;
                maxxplace[i]=2;
                if(a[i].q>a[i].e)
                {
                    sec[i]=a[i].q;
                    secplace[i]=1;
                }
                else{
                    sec[i]=a[i].e;
                    secplace[i]=3;
                }
            }
            else{
                maxx[i]=a[i].e;
                maxxplace[i]=3;
                if(a[i].w>a[i].q)
                {
                    sec[i]=a[i].w;
                    secplace[i]=2;
                }
                else{
                    sec[i]=a[i].q;
                    secplace[i]=1;
                }
            }
        }
        int xiaocha[n+1];
        for (int i=1;i<=n;i++)
        {
            int z1=min(lm[i],mr[i]);
            int z2=min(lr[i],z1);
            xiaocha[i]=z2;
        }
        for (int i=1;i<=n;i++)
        {
            int k=-1;
            int place =-1;
            for (int j=1;j<=n;j++)
            {
                if(xiaocha[i]>k&&xiaocha[i]!=-1)
                {
                    k = xiaocha[i];
                    place = i;
                }
                if(xiaocha[i]==k&&place!=-1)
                {
                    if(maxx[i]>maxx[place])
                    {
                        k = xiaocha[i];
                        place = i;
                    }
                }

            }
            xiaocha[place]=-1;
            if(ch[maxxplace[place]]<mid)
            {
                sum+=maxx[place];
                ch[maxxplace[place]]++;
            }
            else
            {
                sum+=sec[place];
                ch[secplace[place]]++;
            }


        }
        cout<<sum<<endl;


    }
    return 0;
}
