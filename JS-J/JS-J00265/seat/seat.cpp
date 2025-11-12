#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,s=0,as;
struct stu
{
    int x,r;
    bool operator<(const stu t) const
    {
        return x>t.x;
    }
}a[10005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i].x;
    a[1].r=1;
    sort(a+1,a+(n*m)+1);
    for(int i=1;i<=n*m;i++)
        if(a[i].r==1)
        {
            as=i;
            break;
        }
    s++;
    if(s==as)
    {
        cout<<y<<" "<<x<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(i%2==1)
                x++;
            else
                x--;
            s++;
            if(s==as)
            {
                cout<<y<<" "<<x<<endl;
                return 0;
            }
        }
        y++;
        s++;
        if(s==as)
        {
            cout<<y<<" "<<x<<endl;
            return 0;
        }
    }
    return 0;
}
