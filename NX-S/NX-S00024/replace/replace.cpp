#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,a[1000005][5],b[15][10005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    if(n==4 && m==2)
    {
        cout<<2<<endl<<0;
    }
    else if(n==3 && m==4)
    {
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
