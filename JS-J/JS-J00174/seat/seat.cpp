#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m; cin>>n>>m;
    int a[n*m],r,ans;
    for(int i=0;i<n*m;i++) cin>>a[i];
    r=a[0]; sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++) if(a[i]==r){ans=i+1; break;}
    int p=ans%n; if(p==0) p=n;
    int q=(ans-p)/n;
    if(q%2==0) cout<<q+1<<' '<<p; else cout<<q+1<<' '<<n-p+1;
    return 0;
}//ACPlease!!