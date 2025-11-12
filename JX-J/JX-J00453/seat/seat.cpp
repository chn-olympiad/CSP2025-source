#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,flag,c,r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(cnt==a[i]){
            flag=i;
            break;
        }
    }
    if(flag%n!=0)c=flag/n+1;
    if(c%2!=0){
        r=flag%n;
        if(r==0)r=n;
    }
    else{
        r=n+1-flag%n;
        if(r==n+1)r=1;
    }
    cout<<c<<" "<<r;
    return 0;
}
