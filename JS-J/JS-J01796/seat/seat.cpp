#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int a[200];
int h,l;
int ans;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    num=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==num)
        {
            ans=i;
            break;
        }
    }
    l=ans/n+1;
    h=ans%n;
    if(!h)h=n,l--;
    if(!(l%2))h=n+1-h;
    cout<<l<<" "<<h;
    return 0;
}
