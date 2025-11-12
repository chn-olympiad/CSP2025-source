#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,r;
    cin>>n>>m>>r;
    int hi=1;
    for(int i=2;i<=n*m;i++){
        int x;
        cin>>x;
        if(x>r)hi++;
    }
    int l=(hi+n-1)/n;
    int h=(l&1==1?hi-(l-1)*n:n+1-hi+(l-1)*n);
    cout<<l<<" "<<h;
    return 0;
}
