#include<bits/stdc++.h>;
using namespace std;
long long n,N,maxx=-1;
struct qw
{
    long long a1,a2,a3;
    bool vis=1;
}a[100064];
bool cmp(qw a,qw b)
{
    return a.a1<b.a1;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j].a1>>a[j].a2>>a[j].a3;
        }
        long long sum=0;
        sort(a+1,a+1+n,cmp);
        for(int j=1;j<=n;j++)
        {
            sum+=max(a[j].a1,max(a[j].a2,a[j].a3));
        }
        cout<<sum<<endl;

    }
    return 0;
}
