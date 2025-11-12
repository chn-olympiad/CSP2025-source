#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,m;
int rank1=1;
signed main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int s;
    cin>>s;
    for(int i=2;i<n*m;i++) {
        int x;
        cin>>x;
        if(x>s) rank1++;
    }
    if(rank1 <= n) {
        cout<<"1 "<<rank1<<"\n";
    } else {
        int ll=rank1%n;
        int hh=(rank1-ll)/n+1;
        if(hh%2==0) {
            cout<<hh<<" "<<n-ll+1<<"\n";
        } else {
            cout<<hh<<" "<<ll<<"\n";
        }
    }
    return 0;
}