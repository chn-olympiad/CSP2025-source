#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=205;
int n,m,k,ki,x,y,s[len];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
        if(i==1) k=s[i];
    }
    sort(s+1,s+1+n*m);
    ki=lower_bound(s+1,s+1+n*m,k)-s;
    ki=n*m-ki+1;
    x=(ki-1)/n+1,y=ki%n;
    if(y==0) y=n;
    if(x%2==0) y=n-y+1;
    cout<<x<<' '<<y<<'\n';
    return 0;
}
