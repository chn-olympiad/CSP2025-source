#include <bits/stdc++.h>
using namespace std;

int a[200];
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int k=a[1];
    int cnt;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k) cnt=i;
    }
    int x,y;
    y=ceil(1.0*cnt/n);
    if(y%2==1){
        x=cnt-(y-1)*n;
    }
    else{
        int p=(y-1)*n;
        cnt-=p;
        x=n+1-cnt;
    }
    cout<<y<<' '<<x;
    return 0;
}
