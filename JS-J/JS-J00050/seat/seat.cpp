#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct node{
    int a,b;
}a[105];
bool cmp(node a,node b){
    if(a.a>b.a) return 1;
    return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i].a;
        a[i].b=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int w=0;
    for(int i=1; i<=n*m; i++){
        if(a[i].b==1) w=i;
    }
    if(w%n==0){
        int t=w/n;
        if(t%2==1) cout<<t<<" "<<n;
        else cout<<t<<" "<<1;
    }else{
        int t=w/n+1,p=w%n;
        if(t%2==1) cout<<t<<" "<<p;
        else cout<<t<<" "<<n-p+1;
    }
    return 0;
}
