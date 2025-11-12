#include<bits/stdc++.h>
using namespace std;
int a[205];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int kk=a[1],ad=0;
    sort(a+1,a+n+1);
    int pos;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==kk)
        {
            pos=n+1-i;
        }
    }
    while(pos>0)
    {
        pos-=n;
        ad++;
    }
    pos+=n;
    ad--;
    if(ad%2==1)
    {
        cout<<ad<<" "<<n+1-pos;
    }
    else{ cout<<ad<<" "<<pos;}
}
