#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt=0,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(ll i=1,sr;i<=n;i++)
        for(ll j=1;j<=m;j++)
            if(i==1&&j==1)
                cin>>r;
            else
                cin>>sr,cnt+=(sr>r);
    ++cnt;
    cout<<(cnt-1)/n+1<<" ";
    if(((cnt-1)/n+1)&1)
        cout<<(cnt-1)%n+1<<"\n";
    else
        cout<<n-((cnt-1)%n+1)+1<<"\n";
    return 0;
}
