#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
int n,m,v,pos;
bool cmp(int x,int y){return x>y;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    v=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==v) pos=i-1;
    cout<<pos/n+1<<" "<<((pos/n)%2==0?pos%n+1:n-pos%n);
    return 0;
}

