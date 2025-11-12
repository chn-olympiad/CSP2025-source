#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],k,z,s;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    z=n*m;
    for(int i=0;i<z;i++) cin>>a[i];
    k=a[0];
    sort(a,a+z);
    for(int i=0;i<z;i++)
    {
        if(a[i]==k) s=z-i;
    }
    if((s-1)/n%2==0)
    {
        cout<<(s/n)+1<<" "<<(s%n)+1;
    }
    else if((s-1)/n%2==1)
    {
        cout<<(s/n)+1<<" "<<n-(s%n)+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
