#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
struct node{
    int id,d;
}a[N];
int n,m,tot,nowx,nowy=1,nowf,dq;
bool cmp(node x,node y){
    return x.d>y.d;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    tot=n*m;
    for(int i=1;i<=tot;i++){
        cin>>a[i].d;
        a[i].id=i;
    }
    sort(a+1,a+1+tot,cmp);
    for(int i=1;i<=tot;i++){
        if(nowf&1) nowx--;
        else nowx++;
        if(nowx==n+1){
            nowf++;
            nowx=n;
            nowy++;
        }
        if(nowx==0){
            nowx=1;
            nowy++;
            nowf++;
        }
        dq++;
        if(a[dq].id==1){
            cout<<nowy<<" "<<nowx;
            return 0;
        }
    }
    return 0;
}
