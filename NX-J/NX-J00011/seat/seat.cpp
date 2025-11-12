
#include<bits/stdc++.h>
using namespace std;
int n,m,fen[105],r,l,h,hao=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>fen[i];
    }
    r=fen[1];
    for(int i=1;i<n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(fen[i]<fen[j])   swap(fen[i],fen[j]);
        }
    }
    while(fen[hao]!=r)  hao++;
    l=hao/(2*n)*2;
    hao%=2*n;
    if(hao>=1&&hao<=n)
    {
        l++;
        h=hao;
    }
    if(hao>=n+1&&hao<=2*n)
    {
        l+=2;
        h=n-(hao%n)+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
