#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //
    int n,m,sum,k,l,h;
    int a[101];
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    sum=a[0];
    for(int i=0;i<n*m;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==sum)
        {
            k=i;
            continue;
        }
    }
    if(k%m==0&&(k/m)%2==1)
    {
        l=k/m;
        h=1;
    }else if(k%m==0&&(k/m)%2==0)
    {
        l=k/m;
        h=n;
    }else if(k%m!=0&&(k/m)%2==1)
    {
        l=k/m+1;
        h=k%m;
    }else if(k%m!=0&&(k/m)%2==0)
    {
        l=k/m+1;
        h=n-(k%m);
    }
    cout<<l<<" "<<h;
    return 0;
}
