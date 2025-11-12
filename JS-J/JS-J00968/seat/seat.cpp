#include<bits/stdc++.h>
using namespace std;

int n,m,seat_sco[225],a;

bool cmp(int a,int b){return a>b;}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>seat_sco[i];
        if(i==1) a=seat_sco[1];
    }

    sort(seat_sco+1,seat_sco+m*n+1,cmp);

    int as=0;
    for(int i=1;i<=m*n;i++)
    {
        if(seat_sco[i]==a)
        {
            as=i;
            break;
        }
    }

    int tm=as/n+1;
    if(as%n==0) tm-=1;
    int x=as-(tm-1)*n;
    cout<<tm<<' '<<((tm&1)?x:(n-x+1));

    return 0;
}
