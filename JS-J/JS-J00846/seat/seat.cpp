#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,sum,ans1=1;
struct node{
    int sz,id;
}a[121];
bool cmp(node x,node y){
    return x.sz>y.sz;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i].sz,a[i].id=i;
    cnt=a[1].id;
    sum=a[1].sz;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].sz==sum){
            cnt=i;
            break;
        }
    }
    if(cnt%n==0) ans1=cnt/n;
    else ans1=cnt/n+1;
    cout<<ans1<<" ";
    if(ans1%2==1){
      if(cnt%n==0) cout<<n;
      else cout<<cnt%n;
    }
    else{
        if(cnt%n==0) cout<<1;
        else cout<<n-cnt%n+1;
    }
    return 0;
}
