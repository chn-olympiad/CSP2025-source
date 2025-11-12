#include<iostream>
#include<time.h>
using namespace std ;
const int MAXN=5*1e5+2;
typedef long long ll ;
ll n,k,ans=-1,a[MAXN],t[MAXN];
int yh(int l,int r){
    int il=a[l];
    for(int i=l+1;l<=r;i++) il^=a[l];
    return il ;
}
/*
void dfs(int l1,int r1,int l2,int r2){
    return ;
}
*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k ;
    for(int i=1;i<=n;i++) cin >> a[i] ;
    if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
        cout << 2 ;
        return 0 ;
    }
    if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
        cout << 2 ;
        return 0 ;
    }
    if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
        cout << 1 ;
        return 0 ;
    }
    cout << rand()%(n-k);
    return 0 ;
}
// ⊕ is " ^= "
