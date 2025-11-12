#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool m_m(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int wyc;
    int i;
    i=1;
    while(i<=n*m)
        {
            cin>>a[i];
            ++i;
        }
    wyc=a[1];
    sort(a+1,a+n*m+1,m_m);
    i=1;
    while(i<=n*m)
        {
            if(a[i]==wyc)
                {
                    if((i-1)/n%2==0)
                        {
                            cout<<(i-1)/n+1<<' '<<(i-1)%n+1;
                        }
                    else
                        {
                            cout<<(i-1)/n+1<<' '<<n-(i-1)%n;
                        }
                    break;
                }
            ++i;
        }
    return 0;
}