#include <bits/stdc++.h>
using namespace std;
const int N=150;
int a[N],n,m,d;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int s=a[1];
    sort(a,a+n*m+1);
    for(int i=n*m;i>=0;i--)
    {
        d++;
        if(a[i]==s) break;
    }
    int l=d/n,h;
    if(d%n!=0) l++;
    if(l%2==0) h=n*l-d+1;
    else h=d-n*(l-1);
    cout<<l<<" "<<h<<endl;
    return 0;
}
