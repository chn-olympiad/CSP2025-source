#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[11][11];
    int b[101];
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    x=b[1];
    sort(b+1,b+n*m+1,cmp);
    int q;
    for(int i=1;i<=n*m;i++)
    {
       if(b[i]==x)
       {
           q=i;
           break;
       }
    }
    if(q>=1&&q<=n)
    {
        cout<<"1"<<" "<<q;
        return 0;
    }
    if(q>=n+1&&q<=2*n)
    {
        cout<<"2"<<" "<<2*n+1-q;
        return 0;
    }
    if(q>=2*n+1&&q<=3*n)
    {
        cout<<"3"<<" "<<q-2*n;
        return 0;
    }
    if(q>=3*n+1&&q<=4*n)
    {
        cout<<"4"<<" "<<4*n+1-q;
        return 0;
    }
    if(q>=4*n+1&&q<=5*n)
    {
        cout<<"5"<<" "<<q-4*n;
        return 0;
    }
    if(q>=5*n+1&&q<=6*n)
    {
        cout<<"6"<<" "<<6*n+1-q;
        return 0;
    }
    if(q>=6*n+1&&q<=7*n)
    {
        cout<<"7"<<" "<<q-6*n;
        return 0;
    }
    if(q>=7*n+1&&q<=8*n)
    {
        cout<<"8"<<" "<<8*n+1-q;
        return 0;
    }
    if(q>=8*n+1&&q<=9*n)
    {
        cout<<"9"<<" "<<q-8*n;
        return 0;
    }
    if(q>=9*n+1&&q<=10*n)
    {
        cout<<"10"<<" "<<10*n+1-q;
        return 0;
    }
}
