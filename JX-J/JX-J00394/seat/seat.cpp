#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n,m,a[N];
int x;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)x=a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            x=i;
            break;
        }
    }
    int nl=x/n,ml=x-nl*n;
    if(ml==0){
        if(nl%2==0){
            cout<<nl<<" "<<1;
        }
        else{
            cout<<nl<<" "<<n;
        }
    }
    else{
        if(nl%2==0){
            cout<<nl+1<<" "<<ml;
        }
        else{
            cout<<nl+1<<" "<<n-ml+1;
        }
    }
    return 0;
}
