#include<bits/stdc++.h>
using namespace std;
struct myd
{
    int id,bm,my;
}brr[300015];
int tt[100005],trr[5];
bool cmp(myd a,myd b)
{
    return a.my<b.my;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(trr,0,sizeof(trr));
        memset(tt,0,sizeof(tt));
        long long ans=0;
        int n;
        cin>>n;
        for(int j=1;j<=n;j++)
            for(int k=1;k<=3;k++)
            {
                int a;
                cin>>a;
                brr[(j-1)*3+k]={j,k,a};
            }
        sort(brr+1,brr+1+n*3,cmp);
        for(int j=n*3;j>=1;j--)
        {
            if(tt[brr[j].id]||trr[brr[j].bm]*2==n)continue;
            tt[brr[j].id]=1;
            trr[brr[j].bm]++;
            ans+=brr[j].my;
        }
        cout<<ans<<endl;
    }
    return 0;
}
