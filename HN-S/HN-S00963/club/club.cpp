#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x;
}
int test_cnt;
int n,cnt0,cnt1,cnt2,ans,a[110000][3],dl[110000],p[3][110000];
bool cmp(int a,int b)
{
    return dl[a]>dl[b];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int M,i;
    test_cnt=read();
    while(test_cnt)
    {
        test_cnt--;
        cnt0=cnt1=cnt2=ans=0;
        n=read();
        for(i=1;i<=n;i++)
        {
            a[i][0]=read();
            a[i][1]=read();
            a[i][2]=read();
            M=max(a[i][0],max(a[i][1],a[i][2]));
            ans+=M;
            if(M==a[i][0])
            {
                cnt0++;
                p[0][cnt0]=i;
                dl[i]=a[i][0]-max(a[i][1],a[i][2]);
            }
            else if(M==a[i][1])
            {
                cnt1++;
                p[1][cnt1]=i;
                dl[i]=a[i][1]-max(a[i][0],a[i][2]);
            }
            else
            {
                cnt2++;
                p[2][cnt2]=i;
                dl[i]=a[i][2]-max(a[i][0],a[i][1]);
            }
        }
        if(cnt0>n/2)
        {
            sort(p[0]+1,p[0]+cnt0+1,cmp);
            for(i=n/2+1;i<=cnt0;i++)
                ans-=dl[p[0][i]];
        }
        else if(cnt1>n/2)
        {
            sort(p[1]+1,p[1]+cnt1+1,cmp);
            for(i=n/2+1;i<=cnt1;i++)
                ans-=dl[p[1][i]];
        }
        else if(cnt2>n/2)
        {
            sort(p[2]+1,p[2]+cnt2+1,cmp);
            for(i=n/2+1;i<=cnt2;i++)
                ans-=dl[p[2][i]];
        }
        printf("%d\n",ans);
    }
    return 0;
}
