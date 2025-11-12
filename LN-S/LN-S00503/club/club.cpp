#include <bits/stdc++.h>
using namespace std;
int t,n,total;
int a[100005],b[100005],c[100005];
int cf[100005];//pos[100005];
int maxn[100005],minn[100005];
int idf[100005],ids[100005];
int sum[5];
bool flaga;
int f(int x,int y)
{
    if(x==1)
    {
        return a[y];
    }
    else if(x==2)
    {
        return b[y];
    }
    else
    {
        return c[y];
    }
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=3;i++)
        {
            sum[i]=0;
        }
        total=0;
        memset(a,sizeof(a),0);
        memset(b,sizeof(b),0);
        memset(c,sizeof(c),0);
        flaga=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            //pos[i]=i;
            if(a[i]>=max(b[i],c[i]))
            {
                idf[i]=1;
                maxn[i]=a[i];
                if(b[i]>c[i])
                {
                    ids[i]=2;
                    cf[i]=a[i]-c[i];
                    minn[i]=b[i];
                }
                else
                {
                    ids[i]=3;
                    cf[i]=a[i]-b[i];
                    minn[i]=c[i];
                }
            }
            else if(b[i]>=max(a[i],c[i]))
            {
                idf[i]=2;
                maxn[i]=b[i];
                if(a[i]>c[i])
                {
                    ids[i]=1;
                    cf[i]=b[i]-c[i];
                    minn[i]=a[i];
                }
                else
                {
                    ids[i]=3;
                    cf[i]=b[i]-a[i];
                    minn[i]=c[i];
                }
            }
            else
            {
                idf[i]=3;
                maxn[i]=c[i];
                if(a[i]>b[i])
                {
                    ids[i]=1;
                    cf[i]=c[i]-b[i];
                    minn[i]=a[i];
                }
                else
                {
                    ids[i]=2;
                    cf[i]=c[i]-a[i];
                    minn[i]=b[i];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(minn[i]!=0)
            {
                flaga=false;
            }
        }
        if(flaga==true)
        {
            sort(maxn+1,maxn+1+n,cmp);
            for(int i=1;i<=n/2;i++)
            {
                total+=maxn[i];
            }
            cout<<total<<endl;
            continue;
        }
        //sort(cf+1,cf+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(cf[i]<cf[j])
                {
                    swap(cf[i],cf[j]);
                    swap(maxn[i],maxn[j]);
                    swap(minn[i],minn[j]);
                    swap(idf[i],idf[j]);
                    swap(ids[i],ids[j]);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(sum[idf[i]]>=n/2)
            {
                sum[ids[i]]++;
                total+=minn[i];
            }
            else
            {
                sum[idf[i]]++;
                total+=maxn[i];
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
