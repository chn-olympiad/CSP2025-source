#include<bits/stdc++.h>
using namespace std;
/*int RP;
RP++;*/
int big(int a,int b)
{
    return a>b;
}
int ak=0,ac=0,n,m,s[10000],num;
int main()
{
    freopen("seat.in",r,stdin);
    freopen("seat.out",w,stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>s[i];
    }
    int score=s[0];
    sort(s,s+n*m,big);
    for(int i=0;i<n*m;i++)
    {
        if(s[i]==score) num=i;
    }
    for(int i=0;i<n*m;i++)
    {
        num--;
        if(num==-1) break;
        if(ak<n-1 and ac%2==0) ak++;
        else if(ak>0 and ac%2!=0) ak--;
        else if(ak==n-1 and ac%2==0) ac++;
        else if(ak==0 and ac%2!=0) ac++;
    }
    ak++;
    ac++;
    cout<<ac<<" "<<ak;
    return 0;
}
