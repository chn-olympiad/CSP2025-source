#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int y=a[1];
    sort(a,a+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==y){
            y=i;
            break;
        }
    }
    int s[n+1][m+1];
    int l=0,h=0;
    if(y%n==0)  l=y/n;
    else    l=y/n+1;
    if(y%(2*n)==0||y%(2*n)==1){
        h=1;
        cout<<l<<" "<<h;
        return 0;
    }
    y%=2*n;
    if(y<=n) h=y;
    if(y>n) h=(n+1)-(y-n);
    cout<<l<<" "<<h;
    return 0;
}
