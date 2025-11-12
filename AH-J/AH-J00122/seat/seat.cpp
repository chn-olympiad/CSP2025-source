#include<bits/stdc++.h>
using namespace std;
int a[105];
bool mapp[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int N=n*m,r=a[1];
    sort(a+1,a+1+N);
    if(a[N]==r)
    {
        cout<<"1 1";
        return 0;
    }
    else if(a[1]==r)
    {
        cout<<m<<" "<<n;
        return 0;
    }
    int l=N;
    while(a[l]>=r)--l;
    l=N-l-1;
    int f=0,x=1,y=1;
    while(l>0)
    {
        if(y==n&&f%2==0||y==1&&f%2==1)
        {
            x++;
            f++;
        }
        else if(f%2==0)y++;
        else y--;
        //cout<<x<<" "<<y<<"\n";
        l--;
    }
    cout<<x<<" "<<y;
    return 0;
}
