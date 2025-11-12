#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[105];
bool cmp(int a,int b){
    return b<a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    int p=a[1],r;
    sort(a+1,a+1+t,cmp);
    for(int i=1;i<=t;i++){
        if(a[i]==p){
            r=i;
            break;
        }
    }
    if(r%m==0) cout<<r/m<<" ";
    else cout<<r/m+1<<" ";
    int k=r%(2*m);
    if(k==0) cout<<1;
    else if(k>=1&&k<=m) cout<<k;
         else cout<<2*m-k+1;
    return 0;
}
