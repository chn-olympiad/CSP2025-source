#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s=1,c;
    cin>>n>>m;
    int a[n*m];
    cin>>a[0];
    for(int i=1;i<n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[0])s++;
    }
    c=s/n;
    s--;
    if((s+1)%n!=0)cout<<s/n+1<<" ";
    else {
        cout<<(s+1)/n<<" ";
        cout<<n;
        return 0;
    }
    s++;
    if(c%2==0)cout<<s%n;
    else
    {
        c=s%n;
        cout<<n-c+1;
    }
    return 0;
}
