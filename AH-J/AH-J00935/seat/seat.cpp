#include<bits/stdc++.h>
using namespace std;
int a[101];
int id[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1);
    int c=1;
    for(int i=n*m;i>0;i--)
    {
        id[a[i]]=c;
        c++;
    }
    int l=id[x]/n+1;
    int h=id[x]%n;
    if(h==0)
    {
        h=n;
        l=l-1;
    }
    if(l%2==0)
    {
        h=n-h+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
