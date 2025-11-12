#include<bits/stdc++.h>
using namespace std;

int n,m,a[1010];
bool cmp(int a,int b){
    return a>b; 
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int ming=a[1];
    sort(a+1,a+1+n*m,cmp);
    int idx=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==ming) idx=i;
    }
    if(idx/n%2==0) cout<<(idx%n==0?idx/n:idx/n+1)<<" "<<idx%n;
    else cout<<(idx%n==0?idx/n:idx/n+1)<<" "<<n-(idx%n==0?idx%n:idx%n-1);

    return 0;
}