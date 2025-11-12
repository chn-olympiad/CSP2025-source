#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define f(i,a,b) for(int i=a;i<b;++i)
#define f2(i,a,b) for(int i=a;i<=b;++i)
#define LEN(x) (int)x.size()
const int inf=0x3f3f3f3f;
const int maxn=1e2+5;
int n,m;
int a[maxn];
int pos=0;
int r=0,c=0;
bool cmp(int t1,int t2){
    return t1>t2;
}
void solve();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int T=1; 
    // cin>>T;
    while(T--) solve();
    return 0;
}
void solve(){
    cin>>n>>m;
    f(i,0,n*m) cin>>a[i];
    int p=a[0];
    sort(a,a+n*m,cmp);
    f(i,0,n*m){
        if(p==a[i]){
            pos=i;
            break;
        }
    }
    r=pos/n+1,c=pos%(2*n);
    if(c<n) ++c;
    else c=2*n-c;
    cout<<r<<" "<<c<<endl;
}