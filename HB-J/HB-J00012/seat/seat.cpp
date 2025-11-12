#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a=n*m;
    int s[a+5],x,p=0;
    for(int i=1;i<=a;i++) cin>>s[i];
    x=s[1];
    sort(s+1,s+a+1);
    for(int i=a;i>=1;i--)
    {
        p++;
        if(s[i]==x)break;
    }
    int hs=0,ls=0;
    ls=p/n,p%=n;
    if(p>0) ls++;
    if(ls%2==1)
    {
        if(p==0) hs=m;
        else hs=p;
    }
    else
    {
        if(p==0) hs=1;
        else hs=n-p+1;
    }
    if(n==1&&m==1) cout<<"1 1";
    else cout<<ls<<" "<<hs;
    return 0;
}
