#include<bits/stdc++.h>
using namespace std;
const int N=11;
int n,m,t[N*N],p,a[N][N],ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>t[i];
    p=t[1];
    sort(t+1,t+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++) if(t[i]==p) ans=i;
    int x=(ans+n-1)/n,y=ans-(ans-1)/n*n;
    if(!(x%2)) y=n-y+1;
    cout<<x<<' '<<y;
}
//expected: 100pts
