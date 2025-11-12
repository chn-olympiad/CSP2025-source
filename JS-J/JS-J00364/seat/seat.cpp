#include<bits/stdc++.h>
using namespace std;
int n,m,R,num,ans1=1,ans2=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>R;
    for(int i=2;i<=n*m;i++)
    {
        int f;
        cin>>f;
        if(f>R)
        {
            num++;
        }
    }
    for(int i=1;i<=num;i++)
    {
        if(ans2==n&&ans1%2==1)
        {
            ans1++;
        }
        else if(ans2==1&&ans1%2==0)
        {
            ans1++;
        }
        else if(ans1%2==1)
        {
            ans2++;
        }
        else if(ans1%2==0)
        {
            ans2--;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
