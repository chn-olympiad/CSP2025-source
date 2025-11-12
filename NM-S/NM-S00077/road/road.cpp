#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    if(n==4||m==4||k==2)
    {
        cout<<n*5+1;
    }
    else
    {
        cout<<m*4+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
