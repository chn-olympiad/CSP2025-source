#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,a[maxn],num,cnt,ans;
bool bj(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    num=a[1];
    sort(a+1,a+n*m+1,bj);
    for(int i=1;i<=n*m;i++)
        if(a[i]==num)
        {
            cnt=i;
            break;
        }
    cout<<(cnt+n-1)/n<<" ";
    ans=cnt%n;
    if(!ans)
        ans=n;
    if((cnt+n-1)/n%2==1)
        cout<<ans;
    else
        cout<<m-ans+1;
    return 0;
}