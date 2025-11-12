#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
int b[30][30];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++){
        cin>>a[i];
    }
    int x=a[1],tot=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if((i%2)==1){
            for(int j=1;j<=n;j++){
                tot++;
                if(a[tot]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                tot++;
                if(a[tot]==x){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }

    }
    return 0;
}
