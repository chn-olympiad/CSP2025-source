//xjz0918 CSP-J2025RP++
//From GAN NAN SHI DA FU ZHONG
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],mark,x,y;
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
    mark=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    int s;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==mark)
        {
            s=i;
            break;
        }
    }
    if(s%n>0)
    {
        y=s/n+1;
    }
    else{
        y=s/n;
    }
    cout<<y<<" ";
    if(y%2==0)
    {
        x=n-(s%n)+1;
    }
    else if(y==1){
        x=s;
    }
    else{
        x=s%n;
    }
    cout<<x;
    return 0;
}
