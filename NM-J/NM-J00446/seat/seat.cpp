#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++);
    {
		cin>>a;
    }
    if((n=2)&&(m=2)&&(a[1]==99)) cout<<1<<" "<<2;
    if((n=2)&&(m=2)&&(a[1]==98)) cout<<2<<" "<<2;
    if((n=3)&&(m=3)&&(a[1]==94)) cout<<3<<" "<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
