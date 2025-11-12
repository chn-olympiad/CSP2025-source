#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int b[1010][1010];
int t=1;
int A1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    A1=a[1];
    sort(a+1,a+n*m+1,cmp);
    //cout<<a[1];
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                //cout<<"a"<<i<<j<<t<<endl;
                b[j][i]=a[t];
                t++;
            }
        }
        else{
            for(int j=1;j<=m;j++){
                //cout<<"b"<<i<<j<<t<<endl;
                b[j][i]=a[t];
                t++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                if(b[i][j]==A1){
                    cout<<j<<" "<<i;
                }
        }
    }
    return 0;
}
