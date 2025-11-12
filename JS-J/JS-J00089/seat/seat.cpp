#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
int n,m,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>a[i];
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int pos;
    for(int i=1;i<=n*m;++i)if(a[i]==t){
        pos=i;
        break;
    }
    int k=pos/n,l=pos%n;
    k+=bool(l);
    if(l==0)l=n;
    cout<<k<<' '<<(k%2?l:n-l+1)<<endl;
    return 0;
}
