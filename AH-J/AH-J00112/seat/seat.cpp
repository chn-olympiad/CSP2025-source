#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int f[10010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>f[i];
    int r=f[1];
    sort(f+1,f+1+n*m,cmp);
    int h=1,l=1;
    bool fl=1;
    for(int i=1;i<=n*m;i++){
        int x=f[i];
        a[h][l]=x;
        if(fl) l++;
        else l--;
        if(l>n){
            fl=0;
            l=n;
            h++;
        }
        if(l<1){
            fl=1;
            l=1;
            h++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==r){
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }
    return 0;
}
