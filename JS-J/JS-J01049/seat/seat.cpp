#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=1e5+8;
int n,m,a[15][15],t[108],tg,pos;
string s,ans;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0,x=n*m;i<x;i++)
    {
        cin>>t[i];
        if(i==0)
        {
            tg=t[i];
        }
    }
    sort(t,t+n*m,cmp);
    for(int i=0;i<=n*m;i++)
    {
        if(t[i]==tg)
        {
            pos=i+1;
        }
    }
    int l=ceil(pos/n),h;
    if(pos%n!=0)
    {
        l++;
    }
    if(l%2==1)
    {
        if(pos%n!=0)
        {
            h=pos%n;
        }
        else{
            h=n;
        }
    }
    else{
        if(pos%n!=0)
        {
            h=n-pos%n+1;
        }
        else{
            h=1;
        }
    }
    cout<<l<<" "<<h<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
