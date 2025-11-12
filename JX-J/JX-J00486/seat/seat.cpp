#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n%2==0)
    {
        m=1;
    }
    cout<<n<<' '<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
