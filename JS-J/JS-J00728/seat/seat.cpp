#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s=1;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])s++;
    }
    if(s%n==0)
    {
        cout<<s/n<<" "<<n;
    }
    else
    {
        cout<<s/n+1<<" ";
        if((s/n+1)%2==0)cout<<m-(s%n)+1;
        else cout<<s%n;
    }
}
