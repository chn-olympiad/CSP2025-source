#include<bits/stdc++.h>
using namespace std;
int n,m,a[111],st,x;
bool cmp(int q,int p){
    return q>p;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>st;
    int N=n*m;
    a[0]=st;
    for(int i=1;i<N;i++) cin>>a[i];
    sort(a,a+N,cmp);
    for(int i=0;i<N;i++){
        if(a[i]==st){
            x=i+1;
            break;
        }
    }
    int l,h;
    l=(x-1)/n+1;
    if(l%2==1){
        if(x%n==0) h=n;
        else h=x%n;
    }else{
        if(x%n==0) h=1;
        else h=(n-x%n)+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
