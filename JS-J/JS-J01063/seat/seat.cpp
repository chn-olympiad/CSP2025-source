#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,w,q;
bool cmp(int r,int t){ return r>t;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            k=i;
            break;
        }
    }
    w=(k-1)/n+1;
    cout<<w<<" ";
    if(w%2){
        q=k%n;
        if(!q) q=n;
    }else{
        q=n+1-k%n;
        if(q==n+1) q=n;
    }
    cout<<q;
    return 0;
}
