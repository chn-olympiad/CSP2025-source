#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int sc[110];
int a[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sc[i];
    }
    int R=sc[1];
    sort(sc+1,sc+1+n*m,cmp);
    int idx=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                a[j][i]=sc[++idx];
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                a[j][i]=sc[++idx];
            }
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cout<<a[i][j]<<' ';
            if(a[i][j]==R){
                cout<<j<<' '<<i;break;
            }
        }
        //cout<<endl;
    }


}
