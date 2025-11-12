#include<bits/stdc++.h>
using nmaespace std;
int a[501];
int main()
{
    int n,m,a;
    int sum=0,k=0;
    int y;int w=pow(10,(n-1));
    cin>>n>>m;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        y=a/w;
        if(y>=a[i])
        {
            k++;
        }
        a=a-y*w;
        w=w/10;
    }
    if(k>=m)
    {
        sum=++
    }
    cout<<sum;
    return 0;
}
