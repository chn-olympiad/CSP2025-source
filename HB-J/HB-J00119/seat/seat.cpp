#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x,y,t=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    for(int i=1;i<n*m;i++){
        cin>>y;
        if(y>x) t++;
    }
    if(((t-1)/n)%2==0) cout<<((t-1)/n)+1<<" "<<(t-1)%n+1;
    else cout<<((t-1)/n)+1<<" "<<n-((t-1)%n+1)+1;
    return 0;
}
