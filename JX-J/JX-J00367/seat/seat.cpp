#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct l{
    int num,tot;
}a[105];
bool cmp(l x,l y){
    return x.tot>y.tot;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].tot;
        a[i].num=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int now=0;
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                if(a[++now].num==1){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[++now].num==1){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
