#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y;
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++)
    {
        cin>>a[i];
    }
    int flag = a[1];
    sort(a+1,a+1+l);
    for(int i=1;i<=l;i++)
    {
        if(a[i] == flag)
        {
            flag = i;
            break;
        }
        if(flag == a[l])
        {
            cout<<'1'<<' '<<'1';
            return 0;
        }
    }
    if(m%2==1)
    {
    int ans = flag;
    while(ans<=l)
    {
        if(ans==l)
        {
            x=1,y=1;
        }
        if(ans%n==0){
        int num = ans/n;
        y = m-num+1;
        if(num%2==1) x = 1;
        else x = n;
        break;
        }
        ans++;
    }
    int time = ans-flag;
    {
        if(y%2==1) x+=time;
        if(y%2==0) x-=time;
    }
     cout<<y<<' '<<x;
    }
    else {
        int ans = flag;
    while(ans<=l)
    {
        if(ans==l)
        {
            x=1,y=1;
        }
        if(ans%n==0){
        int num = ans/n;
        y = m-num+1;
        if(num%2==1) x = n;
        else x = 1;
        break;
        }
        ans++;
    }
    int time = ans-flag;
    {
        if(y%2==1) x+=time;
        if(y%2==0) x-=time;
    }
     cout<<y<<' '<<x;
    }
    return 0;
}
