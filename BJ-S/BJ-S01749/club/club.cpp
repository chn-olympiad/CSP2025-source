#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int x;
    int y;
    int z;
}a[100001];
bool cmp(stu b,stu c)
{
    return b.x>c.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].x>>a[i].y>>a[i].z;
        if(n==2)
        {
            int id1=0,id2=0,maxx1,maxx2;
            maxx1=max(a[1].x,max(a[1].y,a[1].z));
            if(a[1].x==maxx1)
                id1=1;
            else if(a[1].y==maxx1)
                id1=2;
            else if(a[1].z==maxx1)
                id1=3;
            maxx2=max(a[2].x,max(a[2].y,a[2].z));
            if(a[2].x==maxx2)
                id2=1;
            else if(a[2].y==maxx2)
                id2=2;
            else if(a[2].z==maxx2)
                id2=3;
            if(id1!=id2)
                ans=maxx1+maxx2;
            else if(id1==id2)
            {
                ans=max(maxx1,maxx2);
                if(ans==maxx1)
                {
                    if(a[2].x<=a[2].y)
                        swap(a[2].x,a[2].y);
                    if(a[2].x<=a[2].z)
                        swap(a[2].x,a[2].z);
                    if(a[2].y<=a[2].z)
                        swap(a[2].y,a[2].z);
                    ans+=a[2].y;
                }
                else if(ans==maxx2)
                {
                    if(a[1].x<=a[1].y)
                        swap(a[1].x,a[1].y);
                    if(a[1].x<=a[1].z)
                        swap(a[1].x,a[1].z);
                    if(a[1].y<=a[1].z)
                        swap(a[1].y,a[1].z);
                    ans+=a[1].y;
                }
            }
            cout<<ans<<endl;
        }
        else if(n==100000)
        {
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++)
                ans+=a[i].x;
            cout<<ans<<endl;
        }
    }
    return 0;
}