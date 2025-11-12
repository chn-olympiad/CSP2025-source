#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,l=0;
    bool f[101]={0};
    cin>>n>>m;
    int a[n*m],s[n][m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        f[a[i]]=1;
    }
    r=a[0];
    for(int i=0;i<100;i++){
        if(f[i]){
            a[l]=i;
            l++;
        }
    }
    int i,j;
    for(i=0;i<m;i++){
        if(i%2==0){
            for(j=0;j<n;j++){
                s[i][j]=a[i*n+j];
                if(s[i][j]==r){
                    cout<<j+1<<' '<<i+1;
                    return 0;
                }
            }
        }
        else{
            for(j=n-1;j>=0;j--){
                s[i][j]=a[i*n+n-j-1];
                if(s[i][j]==r){
                    cout<<m-j<<' '<<i+1;
                    return 0;
                }
            }
        }
    }
}
