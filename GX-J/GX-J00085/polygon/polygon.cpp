#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,c,x;
long long k=998244353;
long long sum;
long long cut=1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
        cout<<0;
    else if(n==3)
    {
        x=max(max(a,b),c);
        if( (a+b+c)>2*x )
        sum++;
        cout<<sum<<endl;
        return 0;
    }
    else
    {
        for(int i=n-2;i<=1;i++)
        {
            sum=(sum%k+(i*cut)%k)%k;
            cut++;
        }
    }
    return 0;
}

