#include<bits/stdc++.h>
using namespace std;

int n,m,k,num=0,c=1,r;
int a[105];

bool cmp(int x,int y)
{
    return x>y;
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
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k)
        {
            num=i;
            break;
        }
    }
    int cnt=num;
    while(1)
    {
        if(num>n) num-=n,c++;
        else if(num<=n)
        {
            if(c%2==0) r=n-num+1;
            else r=num;
            break;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
