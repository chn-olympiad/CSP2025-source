#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,tmp;
int a[105];
inline bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    tmp=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==tmp){
            int c=((i-1)/m)+1,r;
            if(c&1) r=((i-1)%m)+1;
            else r=m-((i-1)%m);
            cout<<c<<' '<<r<<'\n';
            return 0;
        }
    }
    return 0;
}
