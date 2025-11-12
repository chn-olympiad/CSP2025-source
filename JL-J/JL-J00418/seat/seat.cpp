#include<bits/stdc++.h>
using namespace std;
long long a[10002];
long long n,m;
int found(int k)
{
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int k=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    int num=found(k);
    long long c=0,r=0;
    if(num%n==0)
    {
        c=num/n;
    }
    else{
        c=num/n+1;
    }
    if(c%2==1)
    {
        while(num>n)
        {
            num-=2*n;
        }
        r=num;
    }
    else
    {
        num-=2*num;
        while(num<0)
        {
            num+=2*n;
        }
        r=num+1;
    }
    cout<<c<<" "<<r;
    return 0;
}

