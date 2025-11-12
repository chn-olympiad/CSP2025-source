#include<bits/stdc++.h>
using namespace std;
struct Club
{
    int v,a;
}max1[100005],max2[100005],max3[100005];
int a[100005][3];
int cl[3];
bool cmp(Club a,Club b)
{
    return a.v>=b.v;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(max1,0,sizeof(max1));
        memset(max2,0,sizeof(max2));
        memset(max3,0,sizeof(max3));
        memset(cl,0,sizeof(cl));
        int n;
        cin>>n;
        int maxn=n/2;
        if(n==2)
        {
            int maxa=-1;
            cin>>a[1][1]>>a[1][2]>>a[1][3]>>a[2][1]>>a[2][2]>>a[2][3];
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(i!=j)
                    {
                        maxa=max(maxa,a[1][i]+a[2][j]);
                    }
                }
            }
            cout<<maxa<<endl;
            break;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                cin>>a[i][1]>>a[i][2]>>a[i][3];
                max1[i].v=max(a[i][1],max(a[i][2],a[i][3]));
                max3[i].v=min(a[i][1],min(a[i][2],a[i][3]));
                max2[i].v=a[i][1]+a[i][2]+a[i][3]-max1[i].v-max3[i].v;
                for(int j=1;j<=3;j++)
                {
                    if(a[i][j]==max1[i].v) max1[i].a=j;
                    else if(a[i][j]==max2[i].v) max2[i].a=j;
                    else if(a[i][j]==max3[i].v) max3[i].a=j;
                }
            }
            sort(max1+1,max1+1+n,cmp);
            sort(max2+1,max2+1+n,cmp);
            sort(max3+1,max3+1+n,cmp);
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(cl[max1[i].a]<maxn)
                {
                    cl[max1[i].a]++;
                    cnt+=max1[i].v;
                }
                else if(cl[max2[i].a]<maxn)
                {
                    cl[max2[i].a]++;
                    cnt+=max2[i].v;
                }
                else if(cl[max3[i].a]<maxn)
                {
                    cl[max3[i].a]++;
                    cnt+=max3[i].v;
                }
            }
            cout<<cnt<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
