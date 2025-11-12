#include <bits/stdc++.h>
using namespace std;
long long n,id,r,x,y,m,a[105];
bool cmp(int pre,int nxt){
    return pre>nxt;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m*n;i++){
        if(a[i]==r){
            id=i;
            break;
        }
    }
    if(id%n==0) x=id/n;
    else x=id/n+1;
    if(!id%(2*n)||id%(2*n)==1) y=1;
    else for(int i=2;i<=2*n-1;i++){
        if(id%(2*n)==i&&i<=n){
            y=i;
        }
        if(id%(2*n)==i&&i>n) y=2*n-i+1;
    }

    cout<<x<<" "<<y;
    return 0;
}
