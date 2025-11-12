#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1,y=1,p;
vector<long long> a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>p; a.push_back(p);
    for(int i=1;i<n*m;i++)
    {
        long long x;cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end(),greater<long long>());
    for(int i=1;i<=n*m;i++)
    {
        if(y%2==0)x--;
        else x++;
        if(y%2==0&&x==0||y%2==1&&x==n+1)
        {
            y++;
            if(y%2==1)x++;
            else x--;
        }
        if(a[i]==p)
        {
            cout<<y<<' '<<x;
            return 0;
        }
    }
    return 0;
}
