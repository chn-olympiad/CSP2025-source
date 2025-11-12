#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m>>a[0];
    int cnt=0;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
        if(a[i]>a[0])cnt++;
    }
    cout<<cnt/n+1<<" ";
    if(cnt/n%2==0)cout<<cnt%n+1;
    else cout<<n-cnt%n;
    return 0;
}
