#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N],mp[N][N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int sum=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                mp[i][j]=a[cnt++];
            }
        }
        else{
            for(int j=m;j>=1;j--){
                mp[i][j]=a[cnt++];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]==sum){
                cout<<i<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}
