#include<bits/stdc++.h>
using namespace std;
struct student
{
    int c1,c2,c3,maxx;
}a[100005];
int sum=0;
bool cmp(student x,student y)
{
    return x.maxx>y.maxx;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j].c1>>a[j].c2>>a[j].c3;
            a[j].maxx=max(max(a[j].c1,a[j].c2),a[j].c3);
        }
        sort(a+1,a+n+1,cmp);
        int temp=n/2;
        for(int j=1;j<=temp;j++)
        {
            sum+=a[j].maxx;
        }
        cout<<sum<<endl;
    }
    return 0;
}
