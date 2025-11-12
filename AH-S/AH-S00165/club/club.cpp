#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int t;
struct node{
    int a,b,c;
}stu[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int mi=max(stu[i].a,max(stu[i].b,stu[i].c));
                int mj=max(stu[j].a,max(stu[j].b,stu[j].c));
                if(mj>mi) swap(stu[i],stu[j]);
            }
        }
        int maa=0,mab=0,mac=0,ma=0,mb=0,mc=0;
        for(int i=1;i<=n;i++)
        {
            if(stu[i].a>stu[i].b&&stu[i].a>stu[i].c&&ma<n/2)
            {
                maa+=stu[i].a;ma++;
            }
            else
            {
                if(stu[i].b>stu[i].c&&mb<n/2)
                {
                    mab+=stu[i].b;mb++;
                }
                else
                {
                    mac+=stu[i].c;mc++;
                }
            }
        }
        cout<<maa+mab+mac<<endl;
    }
    return 0;
}
