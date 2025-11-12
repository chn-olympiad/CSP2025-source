#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int n,rs1,rs2,rs3,spb,ans,spa,flagg[maxn];
struct aa
{
    int x,y,z;
};
aa a[maxn];
bool cmp1(aa a,aa b)
{
    return a.x>b.x;
}

int main(void)
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        spa=spb=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].y==0 && a[i].z==0)spa++;
        }
        rs1=rs2=rs3=n/2;
        if(spa==n)
        {sort(a,a+n,cmp1);
            for(int i=0;i<n/2;i++)
            {
                ans+=a[i].x;
            }
            cout<<ans;
            continue;
        }

    }
return 0;
}
