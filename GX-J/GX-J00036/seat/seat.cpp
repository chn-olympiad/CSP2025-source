#include<bits/stdc++.h>
using namespace std;
int n,m;
int t;
int q,p;
struct node{
    int cj;
    int bh;
}a[1005];
bool cmp(node u,node v){
    return u.cj>v.cj;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].cj;
        a[i].bh=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].bh==1){
            t=i;
            break;
        }
    }
    if(t%n==0){
        q=t/n;
    }
    else{
        q=t/n+1;
    }
    cout<<q<<" ";
    p=t%n;
    if(q%2==1){
        if(p==0){
            cout<<n;
        }
        else{
            cout<<p;
        }
    }
    else{
        if(p==0){
            cout<<1;
        }
        else{
            cout<<n-p+1;
        }
    }
    return 0;
}
