#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int a[N*N];
int ans[N][N];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int mark;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            mark=a[1];
        }
    }
    sort(a+1,a+n*m+1,cmp);
    int idx=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                ans[i][j]=a[idx];
                idx++;
            }
        }else{
            for(int j=n;j>=1;j--){
                ans[i][j]=a[idx];
                idx++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==mark){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
