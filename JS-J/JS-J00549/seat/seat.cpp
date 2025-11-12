#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],R;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[++cnt];
    R=a[1];
    sort(a+1,a+cnt+1);
    int pos=lower_bound(a+1,a+cnt+1,R)-a;
    pos=cnt-pos+1;
    int col=(pos-1)/(2*n)*2+1,line=pos%(2*n);
    if(line>n)
    {
        ++col;
        line=n+1-(line-n);
    }
    cout<<col<<' '<<line;
    return 0;
}