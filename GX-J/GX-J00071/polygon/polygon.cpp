#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,sum=0;
struct dot
{
    long long num;long long chang;long long longest;
    bool m_use[5005];
};
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    sort(a+1,a+n+1);
    if(n<3) cout<<"0";
    if(n==3&&a[1]+a[2]>a[3]*2) cout<<"1";
    else cout<<"0";
    return 0;
}
