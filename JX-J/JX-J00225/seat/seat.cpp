#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[1005],b[105][105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>a[i];
    }
    R=a[1];
    //cout<<a[1]<<endl;
    sort(a+1,a+1+n*m,cmp);
    int s=0;
    bool x=1;
    for(int i=1;i<=n;i++){
        if(x==1){
            for(int j=1;j<=m;j++){
                    s++;
                b[i][j]=a[s];
                //cout<<x<<" "<<b[i][j]<<" "<<i<<" "<<j<<endl;
                if(b[i][j]==R){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        else if(x==0){
            for(int j=m;j>=1;j--){
                    s++;
                b[i][j]=a[s];
                //cout<<x<<" "<<b[i][j]<<" "<<i<<" "<<j<<endl;
                if(b[i][j]==R){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        x=!x;
    }
    return 0;
}
