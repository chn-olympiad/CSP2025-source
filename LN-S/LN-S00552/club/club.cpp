#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
long long c[100005];
long long d[100005][10];
bool f[1000005];
long long n;
long long ans;
long long v;
void dfs1(int x,int y,int i)
{
        if(x<v&&f[i]==0&&i<=n)
        {
            ans+=a[i];
            f[i]=1;
            cout<<ans<<endl;
            dfs1(x+1,y,i+1);
            f[i]=0;
        }
        else //if(f[i]==1)
        {
            ans-=a[i-1];
        }
        if(y<v&&f[i]==0&&i<=n)
        {
            ans+=b[i];
            f[i]=1;
            cout<<ans<<endl;
            dfs1(x,y+1,i+1);
            f[i]=0;
        }
        else //if(f[i]==1)
        {
            ans-=b[i-1];
        }
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        v=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        if(b[1]==0&&c[1]==0&&b[2]==0&&c[2]==0)
        {
            sort(a+1,a+n+1);
            for(int i=n;i>n/2;i--)
            {
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }

        if(n==2)
        {
            long long aas=0;
            aas+=a[1];
            aas+=b[2];
            ans=max(ans,aas);
            aas=0;
            aas+=a[1];
            aas+=c[2];
            ans=max(ans,aas);
            aas=0;
            aas+=b[1];
            aas+=a[2];
            ans=max(ans,aas);
            aas=0;
            aas+=b[1];
            aas+=c[2];
            ans=max(ans,aas);
            aas=0;
            aas+=c[1];
            aas+=a[2];
            ans=max(ans,aas);
            aas=0;
            aas+=c[1];
            aas+=b[2];
            ans=max(ans,aas);
            aas=0;
        }
        for(int i=1;i<=n;i++)
        {
            d[i][1]=a[i];
            d[i][2]=b[i];
            d[i][3]=c[i];
            d[i][4]=a[i];
            d[i][5]=b[i];
        }
        if(n>2)
        {
            long long aas=0;
            for(int y=1;y<=3;y++)
            {
                for(int i=0;i<=v;i++)
                {
                    for(int j=0;j<=v;j++)
                    {
                        for(int w=1;w<=i;w++)
                        {
                            aas+=d[w][y+2];
                        }
                        for(int w=i+1;w<=v-j;w++)
                        {
                            aas+=d[w][y];
                        }
                        for(int w=v-j+i+1;w<=v+i;w++)
                        {
                            aas+=d[w][y+1];
                        }
                        for(int w=v+1+i;w<=v+1+i+i;w++)
                        {
                            aas+=d[w][y+1];
                        }
                        for(int w=v+i+i+2;w<=n-j;w++)
                        {
                            aas+=d[w][y];
                        }
                        for(int w=n-j+i+1;w<=n;w++)
                        {
                            aas+=d[w][y+2];
                        }
                        ans=max(ans,aas);
                        aas=0;
                    }

                }

            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
//rp++,rp++
/*
while(1)
{
    rp++;
}
*/
