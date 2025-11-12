#include<bits/stdc++.h>
using namespace std;
struct node{
    int id,score;
};
bool cmp(node x,node y){
    return x.score>y.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    node a[110];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int k;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1) k=i;
    }
    int c=int(ceil(k*1.0/n));
    cout<<c<<' ';
    if(k%n==0){
        if(k/n%2==0) cout<<1;
        else cout<<n;
    }
    else{
        if(c%2==0) cout<<n-k%n+1;
        else cout<<k%n;
    }
    return 0;
}
