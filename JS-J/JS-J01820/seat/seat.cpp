#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat","r",stdin);
    freopen("seat","w",stdout);
    long long n,m,a[100001],mc=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1]) mc++;
    }
    if(mc%n==0) cout<<mc/n<<" "<<n;
    else {
        cout<<mc/n+1<<" ";
        if((mc/n+1)%2==1) cout<<mc%n;
        else cout<<n-(mc%n)+1;
    }
    return 0;
}
