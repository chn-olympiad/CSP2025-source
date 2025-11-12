#include<iostream>
#include<algorithm>
using namespace std;
int a[5005];
bool cmp(int x,int y)
{

    return x>y;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];

    }
    sort(a+1,a+n+1,cmp);
    cout<<a[1]+a[2];
    return 0;
}
