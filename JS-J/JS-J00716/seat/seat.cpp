#include<bits/stdc++.h>
//zhe yi ding shi ge bu tong yi wang de lang man gu shi~
using namespace std;
int a[10001],s[100][100];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    int cnt=0;
    sort(a+1,a+1+n*m);
    cnt=n*m;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                s[i][j]=a[cnt];
                cnt--;
            }
        }else{
            for(int i=n;i>=1;i--){
                s[i][j]=a[cnt];
                cnt--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]==p){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
}
