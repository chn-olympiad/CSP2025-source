#include<bits/stdc++.h>
using namespace std;
struct it{
    int x,pla;
};
int n,t,ans;
int flag,maxx,maxy;
int cnt[5];
int a[100010][5],fir[100010];
it cha[100010];
void init()
{
    ans=0;
    memset(a,0,sizeof(a));
    memset(cnt,0,sizeof(cnt));
    memset(cha,0,sizeof(cha));
    memset(fir,0,sizeof(fir));
}
bool cmp(it a,it b)
{
    return a.x>b.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        init();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            maxx=-1;maxy=-1;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(a[i][j]>maxx)
                {
                    maxy=max(maxy,maxx);
                    maxx=a[i][j];
                    flag=j;
                }
                else{
                    maxy=max(maxy,a[i][j]);
                }
            }
            ans+=maxx;
            cnt[flag]++;
            fir[i]=flag;
            cha[i]={maxy-maxx,flag};
        }
        sort(cha+1,cha+n+1,cmp);
        for(int j=1;j<=3;j++)
        {
            if(cnt[j]>(n/2))
            {
                int idx=1;
                for(int k=1;k<=cnt[j]-n/2;k++)
                {
                    while(cha[idx].pla!=j)
                    {
                        idx++;
                    }
                    ans+=cha[idx].x;
                    idx++;
                }
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
