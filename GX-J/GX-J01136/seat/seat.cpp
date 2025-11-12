#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,w[101];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>w[i];
    }
    int r=w[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i;j<=n*m-1;j++)
        {
            if(w[j]<w[j+1])swap(w[j],w[j+1]);
        }
    }
    int y=0;
    for(int i=1;i<=n*m;i++)
    {
        if(w[i]==r)y=i;
    }
    int h=0,l=0;
    if(floor(y/n)%2==1)l=ceil(y/n);
    else l=floor(y/n);
    if(l%2==0)h=n-(y%n);
    else l=y%4;
    cout<<l<<" "<<h;
    return 0;
}
