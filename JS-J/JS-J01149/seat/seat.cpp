#include <bits/stdc++.h>
using namespace std;
int a[105],n,m;
float pos;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int qq=n*m;
    for(int i=1;i<=qq;++i)
    {
        cin>>a[i];
    }
    int ww=a[1];
    sort(a+1,a+qq+1,greater<int>());
    for(int i=1;i<=qq;++i)
    {
        if(a[i]==ww)
        {
            pos=i;
        }
    }
    int a2=1;
    int a1=ceil(pos/n);
    if(a1%2==0)
    {
        a2=m-a1%n;
    }
    else
    {
        a2=a1%n+1;
    }
    cout<<a1<<" "<<a2;
    return 0;
}
