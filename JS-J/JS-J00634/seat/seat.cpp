#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int b[101];
    int n,m,a=0;

    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
        if(b[i]>=b[0]) a++;
    }

    cout<<(a-1)/n+1<<' ';
    if(((a-1)/n+1)%2) cout<<(a-1)%n+1;
    else cout<<n-((a-1)%n);
    return 0;
}
