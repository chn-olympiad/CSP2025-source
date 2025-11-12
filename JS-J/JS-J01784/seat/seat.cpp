#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[100][100];
int sr[110];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>sr[i];
    }
    int mb=sr[1];
    int nm=n*m;
    sort(sr+1,sr+nm+1,cmp);
    /*
    for(int i=1;i<=n*m;i++)
    {
        cout<<sr[i];
    }
    */
    int x=1,y=1,j=1,fx=1,dx=0;
    for(int i=1;i<=nm;i++)
    {
        if(sr[j]==mb)
        {
            cout<<y<<' '<<x;
        }else{
            dx=x+fx;
            if(dx>n){fx*=-1;dx=n;y++;}
            if(dx<1){fx*=-1;dx=1;y++;}
        }
        if(y>m)return 0;
        x=dx;j++;
    }
    return 0;
}
/*
*/
