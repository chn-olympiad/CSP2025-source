#include <bits/stdc++.h>
using namespace std;
int n,m,r,c,f;
struct stu
{
    int score,id;
}a[105];
bool cmp(stu a,stu b)
{
    return a.score>b.score;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)
        cin>>a[i].score;
    for(int i=1;i<=n*m;++i)
        a[i].id=i;
    sort(a+1,a+n*m+1,cmp);
    c=1;
    for(int i=1;i<=n*m;++i)
    {
        if(f==0)
        {
            ++r;
            if(r>n)
            {
                ++c;
                r=n;
                f=1;
            }
        }
        else
        {
            --r;
            if(r<1)
            {
                ++c;
                r=1;
                f=0;
            }
        }
        if(a[i].id==1)
        {
            cout<<c<<" "<<r;
            return 0;

        }
    }
    return 0;
}
