#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<n*m;i++) {
        int a;cin>>a;
        if (a>k) cnt++;
    }
    int x,y;
    if (cnt%n==0) x=cnt/n;
    else x=cnt/n+1;

    if (x%2==1)
        if (cnt%n==0) y=n;
        else y=cnt%n;
    else
        if (cnt%n==0) y=1;
        else y=n-cnt%n+1;
    cout<<x<<" "<<y;
    return 0;
}

// I love CCF forever
// Please give me the scores of 100 pwp
