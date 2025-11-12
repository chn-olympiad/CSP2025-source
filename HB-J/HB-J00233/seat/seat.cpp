#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],b[15][15],cnt,c[150],f=100,d;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    a[1]=d;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            b[i][j]=a[cnt];
            cnt++;
        }
        for(int j=n-1;j>=0;j--){
            b[i][j]=a[cnt];
            cnt++;
        }
    }
    cnt=0;
    for(int f=100;f>=0;f--){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]=f){
                    c[cnt]=b[i][j];
                }
            }
        }
    }
    cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            b[i][j]=c[cnt];
            cnt++;
        }
        for(int j=n-1;j>=0;j--){
            b[i][j]=c[cnt];
            cnt++;
        }
    }
    for(int i=0;i<=m+1;i++){
        for(int j=0;j<=n+1;j++){
            if(b[i][j]=d){
                cout<<i<<j;
            }
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

