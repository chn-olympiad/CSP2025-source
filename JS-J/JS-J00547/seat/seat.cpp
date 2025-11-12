#include <bits/stdc++.h>
using namespace std;

struct student
{
    int id,score;
}a[105];
bool cmp(student a,student b)
{
    return a.score>b.score;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        a[i].id = i;
        cin >> a[i].score;
    }
    sort(a+1,a+n*m+1,cmp);
    int num;
    for (int i=1;i<=n*m;i++)
    {
        if (a[i].id==1)
        {
            num = i;
            break;
        }
    }
    int c=(num+n-1)/n;
    cout << c << " ";
    if (c%2==1)
    {
        cout << num%n+n*(num%n==0);
    }
    else
    {
        cout << n-(num%n+n*(num%n==0))+1;
    }
    return 0;
}
