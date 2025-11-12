#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
int f=0,k;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1) k=a[i];
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k){ f=i;break;}
    }
    int h=0,l=1;
    int ad=1;
    while(f--)
    {
        h+=ad;
        if(h>n) {h=n;ad=-1;l++;}
        if(h<1) {h=1;ad=1;l++;}
    }
    cout<<l<<' '<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
