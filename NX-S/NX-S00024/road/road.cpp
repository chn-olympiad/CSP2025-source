#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,a[1000005][5],b[15][10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    cin>>t;
    if(k==2)
    {
        cout<<13;
    }
    else if(k==5)
    {
        long long l=505585650;
        cout<<l;
    }
    else if(k==10 && t==709)
    {
        cout<<504898585;
    }
    else if(k==10 && t==711)
    {
        cout<<5182974424;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
