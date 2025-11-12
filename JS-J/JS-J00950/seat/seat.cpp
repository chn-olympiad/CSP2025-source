#include<bits/stdc++.h>
#define int long long
#define i1 mofandashabi
#define j1 mofanjiewoshinianyangshou
#define j2 linjunhaoquanjiaqvshi
#define i1 luwangliT4fenshuquanzhuanyidaowoshenshang
int m,n,i1=1,j1=1,i2,j2,zt=1,tot,a[1000],tgt;
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;tot=m*n;
    cin>>a[1];
    tgt=a[1];
    for(int i=2;i<=tot;i++)
        cin>>a[i];
    sort(a+1,a+tot+1);
    while(a[tot]!=tgt)
    {
        tot--;
        j1+=zt;
        if(j1>n||j1<1)zt=-zt,j1+=zt,i1++;
    }
    cout<<i1<<" "<<j1;
    return 0;
}
