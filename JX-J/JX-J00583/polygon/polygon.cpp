#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,sum;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int b=a[1];
    int c=a[2];
    int d=a[3];
    if(b+c+d>2*b)cout<<1;
    return 0;
}
