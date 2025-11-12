#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n,m;
int x,a;
int cnt=0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>x;
    for(int i=1;i<n*m;i++){
        cin>>a;
        if(a>x) cnt++;
    }
    cout<<cnt/n+1<<" ";
    if((cnt/n)%2==0) cout<<cnt%n+1;
    else cout<<n-(cnt%n);
    return 0;
}
