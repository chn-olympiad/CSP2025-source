#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r;
long long cnt;
long long cc,zz;
long long a[100010];
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cnt=n*m;
    for(int i=1;i<=cnt;i++)
    {
        cin>>a[i];
        if(i==1) cc=a[i];
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        if(a[i]==cc) zz=i;
    }
    cout<<zz/m;
    if(zz%m==0) cout<<" "<<m;
    else cout<<" "<<zz%m;
}
