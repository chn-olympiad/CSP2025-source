#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,score;
    cin>>n>>m;
    cin>>score;
    for(int i=1;i<=n*m-1;i++) {
        cin>>a[i];
    } 
    sort(a+1,a+n*m+1);
    int t,mo,x,y;
    for(int i=1;i<=n*m-1;i++) {
        if(score>a[i]&&score<a[i+1]) {
            t=n*m-i+1;
            break;
        }
    }
    mo=t%n;
    if(mo==0) {
       y=t/n; 
       mo=n;
    }
    else y=t/n+1;
    if(y%2!=0) x=mo;
    else x=n-mo+1;
    cout<<y<<" "<<x<<endl; 
    return 0;
}