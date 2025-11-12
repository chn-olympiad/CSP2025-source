#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    r=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    int x=1,y=1,k=1,i=n*m;
    sort(a+1,a+n*m+1);
    while(a[i]!=r){
        x+=k;
        if(x>n){
            x=n;
            k*=-1;
            y++;
        }
        if(x<1){
            x=1;
            k*=-1;
            y++;
        }
        i--;
    }

    cout<<y<<' '<<x<<'\n';
    return 0;
}