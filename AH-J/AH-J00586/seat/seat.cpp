#include<bits/stdc++.h>
using namespace std;
int a[1005];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k,t;
    cin>>n>>m;
    cin>>k;a[1]=k;
    for(int i=2;i<=n*m;i++)cin>>a[i];
    sort(a+1,a+1+(n*m),cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(k==a[i])
        {
            t=i;break;
        }
    }
    int num,numm;
    if(t%n==0){
        num=t/n;numm=t%n+n;
    }
    else{
       num=t/n+1;numm=t%n;
    }
    cout<<num<<" ";
    if(num%2==0)cout<<n-numm+1;
    else cout<<numm;
    return 0;
}
