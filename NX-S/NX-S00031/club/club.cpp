#include <bits/stdc++.h>
using namespace std;
struct myd
{
    int b1;
    int b2;
    int b3;
    int pd=0;
}a[100001];
int b[50001];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,s=0;
    cin>>t;
    for(int m=1;m<=t;m++)
    {
        int n,s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].b1>>a[i].b2>>a[i].b3;
        }

        for(int i=1;i<=n;i++)
        {
            b[i]=a[i].b1;
        }
        sort(b+1,b+n+1,cmp);
        for(int i=1;i<=n/2;i++)
        {
            s+=b[i];
        }
        cout<<s;
    }
    return 0;
}
