#include<bits/stdc++.h>
using namespace std;
bool cmp(int aaa,int bbb)
{
    return aaa>bbb;
}
int ceil(int aaaa,int bbbb)
{
    if(aaaa-aaaa/bbbb*bbbb>0) return aaaa/bbbb+1;
    else return aaaa/bbbb;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int cc=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==cc){
        cout<<ceil(i,n)<<" ";
        if(ceil(i,n)%2==1)
        {
            cout<<i-(i-1)/n*n;
        }
        else
        {
            cout<<n-i+i/n*n+1;
        }
        return 0;
        }
    }
    return 0;
}
