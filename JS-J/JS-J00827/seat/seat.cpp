#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15]={};
int b[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int sr=b[1];
    sort(b+1,b+n*m+1,cmp);
    int numm=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                numm++;
                a[i][j]=b[numm];
            }
        }
        else{
            for(int j=m;j>=1;j--){
                numm++;
                a[i][j]=b[numm];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==sr){
                cout<<i<<' '<<j;
                return 0;
            }
        }

    }
    return 0;
}
