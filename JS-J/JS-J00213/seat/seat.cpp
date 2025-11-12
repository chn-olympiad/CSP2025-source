#include<bits/stdc++.h>
using namespace std;
// /xia LuoFeng_Nanami
const int N=105;
int a[N];
inline bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,len,x;cin>>n>>m;len=n*m;
    for (int i=1;i<=len;i++) cin>>a[i];
    x=a[1];
    sort(a+1,a+len+1,cmp);
    for (int i=1;i<=len;i++){
        if (x==a[i]){
            int xx=i/(2*n)*2,yy=i%(2*n);
            if (!yy) cout<<xx<<' '<<1;
            else if (yy<=n) cout<<xx+1<<' '<<yy;
            else cout<<xx+2<<' '<<2*n-yy+1;
        }
    } 
    return 0;
}