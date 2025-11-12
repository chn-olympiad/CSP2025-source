#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],x,num,lie,hang;
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++)
    {
        cin >> a[i];
        if(i == 1)
            x = a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i<=n*m;i++)
        if(a[i]==x)
            num = i;
    if(num % n != 0)
        lie = num / n + 1;
    else
        lie = num / n;
    if(lie % 2 == 1)
    {
        if(num % n == 0)
            hang = n;
        else
            hang = num % n;
    }
    else
    {
        if(num%n==0)
            hang = 1;
        else
            hang = n - num%n +1;
    }
    cout << lie << " " << hang;
    return 0;
}
