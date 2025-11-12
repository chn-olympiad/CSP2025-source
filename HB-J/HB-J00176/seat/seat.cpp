#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, t, num;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

	cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    t=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++)
        if(a[i]==t)
        {
            num=i;
            break;
        }
    y=(num+n-1)/n;
    int tmp=y*n;
    if(y%2==1)
        x=n-(tmp-num);
    else
        x=tmp-num+1;
    cout<<y<<" "<<x;
    return 0;
}
