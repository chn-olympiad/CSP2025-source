#include <bits/stdc++.h>

using namespace std;
struct node
{
    int sum;
    int p;
}b[100005];

bool cmp(node x,node y)
{
    return x.sum < y.sum;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a[100005][3];
        int x = 0,y = 0,z = 0;
        cin>>n;
        long long ans = 0;
        for(int i = 1;i <= n;i ++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1] > a[i][2])
            {
                if(a[i][3] < a[i][2])
                {
                    ans+=a[i][1];
                    x++;
                    b[i].sum = a[i][1]-a[i][2];
                    b[i].p = 1;
                }
                else if(a[i][3] > a[i][1])
                {
                    ans+=a[i][3];
                    z++;
                    b[i].sum = a[i][3]-a[i][1];
                    b[i].p = 3;
                }
                else
                {
                    ans+=a[i][1];
                    x++;
                    b[i].sum = a[i][1]-a[i][3];
                    b[i].p = 1;
                }
            }
            else
            {
                if(a[i][3] > a[i][2])
                {
                    ans+=a[i][3];
                    z++;
                    b[i].sum = a[i][3]-a[i][2];
                    b[i].p = 3;
                }
                else if(a[i][3] < a[i][1])
                {
                    ans+=a[i][2];
                    y++;
                    b[i].sum = a[i][2]-a[i][1];
                    b[i].p = 2;
                }
                else
                {
                    ans+=a[i][2];
                    y++;
                    b[i].sum = a[i][2]-a[i][3];
                    b[i].p = 2;
                }
            }
        }
        sort(b+1,b+n+1,cmp);
        //cout<<b[1].sum;
        int cnt = 1;
        while(x>n/2)
        {
            if(b[cnt].p == 1)
            {
                ans-=b[cnt].sum;
                x--;
            }
            cnt++;
        }
        while(y>n/2)
        {
            if(b[cnt].p == 2)
            {
                ans-=b[cnt].sum;
                y--;
            }
            cnt++;
        }
        while(z>n/2)
        {
            if(b[cnt].p == 3)
            {
                ans-=b[cnt].sum;
                z--;
            }
            cnt++;
        }
        cout<<ans<<endl;

    }
    return 0;
}
