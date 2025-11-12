#include<bits/stdc++.h>
using namespace std;
int n,m,a[400],s[20][20];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int cj=a[1];
    sort(a+1,a+n*m+1,cmp);
     int h=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==cj){
            h=i;
            break;
        }
    }
    int flag=0;
    int k=1;
    for(int j=1;j<=m;j++){
        if(flag){
            for(int i=n;i>0;i--){
                s[i][j]=k;
                if(k==h){
                    cout<<j<<' '<<i;
                    return 0;
                }
                k++;
            }
        }else{
            for(int i=1;i<=n;i++){
                s[i][j]=k;
                if(k==h){
                    cout<<j<<' '<<i;
                    return 0;
                }
                k++;
            }
        }
        flag=!flag;
    }
    return 0;
}
