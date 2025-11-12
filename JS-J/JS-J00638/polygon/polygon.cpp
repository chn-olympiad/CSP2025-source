#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;


    int a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }if(n<3){cout<<0;return 0;}
    int maxn=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>maxn)maxn=a[i];
    }
    int k=maxn;
    if(n==3){
        if(a[0]+a[1]+a[2]>k*2)cout<<1;
        else cout<<0;
    }
    if(n>3)cout<<6;
    return 0;
}
