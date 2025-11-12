#include <bits/stdc++.h>
using namespace std;
int x,y,a[105],shu,num,cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>x>>y;
    for(int i=1;i<=x*y;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            shu=x;
        }
    } 
    for(int i=1;i<=x*y;i++)
    {
        for(int j=1;j<x*y;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=x*y;i++)
    {
        if(a[i]==shu)
        {
            shu=i;
        }
    }
        if(shu%y==0)
    {
        num=shu/x;
    }
    else
    {
        num=shu/x+1;
    }
    int sum;
    if(num%2==0)
    {
        sum=num*x;
        for(int j=sum;j>sum+1-x;j--)
        {
            cnt++;
            if(j==shu)
            {
                cout<<cnt<<" "<<num<<" ";
            }
        }
    }
    else
    {
        sum=num*x;
        cnt=x;
        for(int j=sum+1-x;j<sum;j++)
        {
            cnt--;
            if(j==shu)
            {
                cout<<cnt<<" "<<num<<" ";
            }
        }
    }
    return 0;
}
