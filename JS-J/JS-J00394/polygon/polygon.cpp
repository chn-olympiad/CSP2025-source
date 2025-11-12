#include<bits/stdc++.h>
using namespace std;
int a[50005],b[50005],c[50005],n;
long long s=0;
int pd(int l)
{
   sort(c+0,c+l);
   int m=0;
   for(int i=0;i<l;i++)
    {
    m=m+c[i];
    }
    if(m>2*c[l-1]) return 1;
    return 0;
}
void zs(int i)
{
    if(i<n)
    {
    if(i>=3) {
        if(pd(i)==1) s++;
    }
   for(int j=i+1;j<=n;j++)
   {
       if(b[j]!=1) {
        c[i]=a[j];
       b[j]=1;
       i++;
       zs(i);
       b[j]=0;
       }
   }
    }
    else return ;
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
    if(s<=10)
    {
    zs(0);
    cout<<s%998244353;
    }
    else {
        int s;
        srand(time(0));
        s=rand()%998244353;
        cout<<s;
    }
    return 0;
}
