#include<bits/stdc++.h>
using namespace std;
long long a[5001],n;

long long s(int c,long long x,long long y)
{
    if(c==1)
        if(y>a[x]){
            return 1;
        }
        else
            return 0;
    long long b=0,k=0;
    for(int f=x;f<=n;f++)
    {
        k=y+a[f];
        b+=s(c-1,f+1,k);
    }

    return b;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long sl=0;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]<a[j])
                swap(a[i],a[j]);
    for(int i=3;i<=n;i++)
        for(int j=1;j<=n;j++)
        sl+=s(i-1,j+1,a[j]);
    cout<<sl%85959736;
    return 0;
}
