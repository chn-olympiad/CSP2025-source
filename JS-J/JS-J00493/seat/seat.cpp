#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=21;
LL n,m,a[N*N],mp[N][N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int tmp=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1;
    for(int i=1;i<=n*m;i++){
        int y=(i%n==0?i/n:i/n+1);
        if(y&1){
            mp[x][y]=a[i];
            if(x<n){
                x++;
            }
        }
        else{
            mp[x][y]=a[i];
            if(x>1){
                x--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==tmp){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
