//100pts
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[103];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r_score=a[1];
    int r_level;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r_score)
        {
            r_level=i;
            break;
        }
    }
    int lie,hang;
    if(r_level%n==0)
    {
        lie=r_level/n;
        hang=n;
    }
    else
    {
        lie=r_level/n+1;
        hang=r_level%n;
    }
    if(lie%2==0)
    {
        hang=n-hang+1;
    }
    cout<<lie<<" "<<hang<<"\n";
    return 0;
}