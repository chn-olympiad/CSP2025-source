#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10+10;
bool cmp(int x,int y){
    return x>y;
}
int n,m,tar,pos[N][N],a[N*N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    tar=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++) pos[i][j]=a[++cnt];
        }
        else{
            for(int j=m;j>=1;j--) pos[i][j]=a[++cnt];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pos[i][j]==tar){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
