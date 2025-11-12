#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,a[105],t;
    cin>>x>>y;
    for(int i=1;i<=x*y;i++){
        cin>> a[i];
    }
    int k=a[1];
    sort(a+1,a+x*y+1);
    for(int i=x*y;i>=1;i--){
        if(a[i]==k)t=i;
    }
    t=x*y-t+1;
    int d=t%(x*2);
    if(d==0)d=2*x;
    if(d<=x&&d!=0)cout <<((t%x==0)?t/x:t/x+1)<<" "<<d;
    else cout <<((t%x==0)?t/x:t/x+1)<<" "<<x*2-d+1;
    return 0;
}
