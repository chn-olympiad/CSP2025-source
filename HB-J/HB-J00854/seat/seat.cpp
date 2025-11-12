#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],b[105],x=2,y=1,t=1;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    if(b[1]==a[1]){
        cout<<1<<' '<<1;
        return 0;
    }
    for(int i=2;i<=n*m;i++){
        if(a[i]==b[1]){
            cout<<x<<' '<<y;
        }
        if((x%m==0||x==1)){
            y++;
            t=0-t;
            continue;
        }
        x+=t;
    }
}
