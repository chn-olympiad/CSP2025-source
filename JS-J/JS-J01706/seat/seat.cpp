#include<bits/stdc++.h>
using namespace std;
int c[11000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum,si;
    cin>>n>>m;
    cin>>sum;
    c[1]=sum;
    for(int i=2;i<=n*m;i++){
        cin>>c[i];
    }
    sort(c+1,c+n*m+1);
    reverse(c+1,c+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(c[i]==sum){
            si=i;
            break;
        }
    }
    int h;
    if(si%n==0) h=si/n;
    else h=si/n+1;
    cout<<h<<" ";
    if(h%2==1){
        if(si%n==0) cout<<n;
        else
        cout<<si%n;
    }
    else{
        int s=si%n;
        if(si%n==0) s=n;
        cout<<n-s+1;
    }
    return 0;
}