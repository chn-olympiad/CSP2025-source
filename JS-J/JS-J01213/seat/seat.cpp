#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>a[1];
    k=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int k1=n*m;
    sort(a+1,a+1+k1);
    for(int i=k1;i>=1;i--)
    {
        if(a[i]==k)
        {
            i=k1-i+1;
            int h=i,h1=i,k2=n*2;
            h/=k2;
            h1%=k2;
            if(h1<=n)
            {
                int ha=h1%n;
                if(ha==0) ha=n;
                int li=h*2+1;
                cout<<li<<" "<<ha<<'\n';
                return 0;
            }
            else 
            {
                int ha;
                if(h1%n==0) ha=1;
                else ha=n-(h1%n)+1;
                int li=h*2+2;
                cout<<li<<" "<<ha<<'\n';
                return 0;
            }
        }
    }
    return 0;
}