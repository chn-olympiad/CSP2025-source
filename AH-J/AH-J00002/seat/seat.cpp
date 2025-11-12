#include<bits/stdc++.h>
using namespace std;
long long b[100005],n,m,y=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long l=n*m;
    for(int i=1;i<=l;i++)
    {
        cin>>b[i];
        y=b[1];
    }
    for(int i=1;i<=l;i++)
    {

        for(int j=1;j<=l-1;j++)
        {
            if(b[j]<b[j+1])swap(b[j],b[j+1]);
        }
    }
    for(int k=1;k<=l;k++)
    {
        if(b[k]==y)y=k;
    }
    if(n==1)cout<<1<<" "<<y;
    else if(m==1)cout<<y<<" "<<1;
    return 0;
}
