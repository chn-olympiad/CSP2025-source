#include <iostream>
#include <algorithm>
using namespace std;
int a[105],n,m;
int row(int f)
{
    if(((f-1)/n+1)%2==1)
    {
        return (f-1)%n+1;
    }
    else
    {
        return (n-(f-1)%n);
    }
}
int lie(int g)
{
    return (g-1)/n+1;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int goal,cnt;
    cin >> n>>m;
    for(int i = 1;i<=n*m;i++)
    {
        cin >>a[i];
    }
    goal=a[1];
    int sum=n*m;
    sort(a+1,a+sum+1);
    for(int i = sum;i>=1;i--)
    {
        if(a[i]==goal)
        {
            cnt=sum-i+1;
        }
    }
    //cout <<cnt;
    cout << lie(cnt)<<" "<<row(cnt);

    return 0;
}
