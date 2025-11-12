#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=100005;
int a[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t;cin>>n>>m;
    int k,c;
    t=n*m;
    for(int i=1;i<=t;i++)
        cin>>a[i];
    k=a[1];
    sort(a+1,a+t+1,cmp);
    for(int i=1;i<=t;i++)
    {
        if(a[i]==k)
        {
            c=i;
            break;
        }
    }
    int value=ceil(c*1.0/n);
    if(value%2==1)
    {
        if(c%n==0)
            cout<<value<<" "<<n;
        else
            cout<<value<<" "<<c%n;
    }
    else
    {
        if(c%n==0)
            cout<<value<<" "<<1;
        else
            cout<<value<<" "<<n-(c%n)+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
