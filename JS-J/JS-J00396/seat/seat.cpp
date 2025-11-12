#include<bits/stdc++.h>
using namespace std;
const int MAXN=10+3;
int a[MAXN*MAXN];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++)
    {
        cin>>a[i];
    }
    int r=a[1],zak=0;
    sort(a+1,a+1+nm,cmp);
    for(int i=1;i<=nm;i++)
    {
        if(a[i]==r) zak=i;
    }
    int c=-1;
    if(zak%m==0)
    {
        cout<<zak/m<<' ';
        c=zak/m;
    }
    else
    {
        cout<<zak/m+1<<' ';
        c=zak/m+1;
    }
    if(c%2) cout<<zak-(c-1)*m<<endl;
    else cout<<n+1-(zak-(c-1)*m)<<endl;
    return 0;
}
