#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,me,x=1,y=1,cut=0;
    cin>>n>>m;
    int a[n*m]={0};
    int b[n][m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        me=a[0];
    }
    if((n==1)&&(m==1)){
        cout<<a[0];
        return 0;
    }
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--){
        b[x][y];
        y++;
        if(y==m){
            x++;
            y=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(me==b[i][j]){
                if(i%2!=0){
                    cout<<i<<" "<<j;
                    break;
                }else{
                    cut=m;
                    for(int z=m;z>=j;z--){
                        cut--;
                    }
                    cout<<i<<" "<<cut;
                    break;
                }
            }
        }
    }
    return 0;
}
