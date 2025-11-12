#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0,w=0,x=1,y=1,cnt=1;
    int a[10000],b[100][100];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    w=a[1];
    sort(a,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==w)
        {
            w=n*m-i+1;
            break;
        }
    }
    if(w==n*m-1)
    {
        if(m%2==1)
        {
            cout<<m<<" "<<n-1;
        }
        else
        {
            cout<<m<<" "<<'2';
        }
        return 0;
    }
    while(cnt!=w)
    {
        if(x==n&&y%2==1)
        {
            y++;
            cnt++;
            //cout<<y<<" "<<x<<"a"<<endl;
        }
        if(y%2==1)
        {
            x++;
            cnt++;
            //cout<<y<<" "<<x<<"b"<<endl;
        }
        if(x==1&&y%2==0)
        {
            y++;
            cnt++;
            //cout<<y<<" "<<x<<"c"<<endl;
        }
        if(y%2==0)
        {
            x--;
            cnt++;
            //cout<<y<<" "<<x<<"d"<<endl;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
