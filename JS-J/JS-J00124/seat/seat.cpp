#include<bits/stdc++.h>
using namespace std;
int cmp(int pre,int nxt){
    return pre>nxt;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+5];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1],y;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r)y=i;
    }
    if(y%m==0)cout<<y/m<<" "<<m;
    else cout<<y/m+1<<" "<<m-y%m+1;
    return 0;
}
