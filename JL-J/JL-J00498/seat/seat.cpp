//80
#include<bits/stdc++.h>
using namespace std;
int n,m;
int scr[200];
int a[20][20];
bool cmp(int x,int y){
    return x>y;
}
int tx=1,ty=1,p=1,r,opt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>scr[i];
        if(i==1) r=scr[i];
    }
    sort(scr+1,scr+1+n*m,cmp);
    int i=1,j=1;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            a[j][i]=scr[p];
            p++;
        }
        i++;
        a[n][i]=scr[p];
        for(j=n;j>=1;j--){
            a[j][i]=scr[p];
            p++;
        }
        i++;
        a[1][i]=scr[p];
        p++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==r) cout<<j<<" "<<i<<endl;
        }
    }
    return 0;
}
