#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
int n,m,myid,now;
bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            now=(i-1)*n+j;
            cin>>a[now];
            if(now==1)myid=a[now];

        }
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int now=(i-1)*n+j;
            if(a[now]==myid){
                cout<<i<<" ";
                if(i&1)cout<<j;
                else cout<<n+1-j;
                break;
            }

        }

    }
    return 0;
}

