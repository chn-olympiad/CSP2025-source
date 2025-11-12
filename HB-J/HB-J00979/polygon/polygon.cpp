#include <bits/stdc++.h>
using namespace std;
long long s1,s2;
int a[5005],n,xx,b[5005];
bool c=1;
bool cmp(int x,int y)
{
    return x<y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n<=3)
    {
        if(a[1]+a[2]+a[3]<=a[3]*2)
        {
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    return 0;
}
