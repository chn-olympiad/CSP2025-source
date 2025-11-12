#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,cnt=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        cnt+=a[i]>a[1];
    }
    int l=(cnt+n-1)/n,h;
    if(l%2==1) h=cnt-(l-1)*n;
    else h=n-cnt+(l-1)*n+1;
    cout<<l<<" "<<h;
    return 0;
}
