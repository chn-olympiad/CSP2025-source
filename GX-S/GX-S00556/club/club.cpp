#include<bits/stdc++.h>
using namespace std;
int t;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        int n,a[100005],b[100005],c[100005];
        long long sum;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        for(int i=1;i<=n/2;i++)
        {
            sum+=a[i];
            sum+=b[i];
        }
        cout <<sum<<endl;;
    }
    return 0;
}
