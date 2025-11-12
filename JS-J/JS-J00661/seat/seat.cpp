#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int u,v,k,w;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(a[i]==k)
            w=i;
    u=(w-1)/(2*n)+1;
    v=(w-1)%(2*n)+1;
    if(v<=n){
        cout<<u*2-1<<" "<<v;
    }
    else{
        cout<<u*2<<" "<<2*n-v+1;
    }
    return 0;
}
