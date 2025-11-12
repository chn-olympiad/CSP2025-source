#include<bits/stdc++.h>
using namespace std;
int n,m,N,score,t,c,r,s;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    N=n*m;
    for(int i=1;i<=N;i++) cin>>a[i];
    score=a[1];
    sort(a+1,a+N+1,cmp);
    for(int i=1;i<=N;i++){
        if(a[i]==score){
            t=i;
            break;
        }
    }
    s=t%n;
    c=(s==0?t/n:t/n+1);
    if(c%2==0){
        if(s==0) r=1;
        else r=n-s+1;
    }else{
        if(s==0) r=n;
        else r=s;
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
