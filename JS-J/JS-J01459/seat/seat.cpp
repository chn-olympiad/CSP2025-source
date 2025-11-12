#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int seat1[15];
    int seat2[105];
    memset(seat2,0,sizeof(seat2));
    int n,m;
    cin>>n>>m;
    int rshu=n*m;

    for(int i=1;i<=rshu;i++)
    {
        cin>>seat1[i];
        seat2[seat1[i]]++;
    }
    int mscore=seat1[1];

    int wzhi=1;
    int c,r;

    for(int i=100;i>=0;i--)
    {
        //cout<<"wzhi"<<wzhi<<endl;
        if(i==mscore)
        {
            break;
        }
        if(seat2[i])
        {
            wzhi+=seat2[i];
        }
    }
    int zdjl=wzhi/n+wzhi%n;
    c=zdjl;
    if(zdjl%2==0)
    {
        if(wzhi%n==0)
        {
            r=1;
        }
        else
        {
            r=n+1-(wzhi%n);
        }
    }
    else
    {
        if(wzhi%n==0)
        {
            r=n;
        }
        else
        {
            r=wzhi%n;
        }
    }
    cout<<c<<" "<<r<<endl;
    //cout<<"wzhi"<<wzhi<<endl;
    return 0;
}
