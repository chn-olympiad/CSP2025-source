#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005],n,m;
int c[105][105],v[105][105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=m*n;
    for(int i=1;i<=s;i++){
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+s+1,cmp);
    c[1][1]=a[1];
    v[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!(i==1&&j==1)){
                if(j%2==0){
                    if(i==1){
                        c[i][j]=a[v[i][j-1]+2*n-1];
                        v[i][j]=v[i][j-1]+2*n-1;
                    }else{
                        c[i][j]=a[v[i-1][j]-1];
                        v[i][j]=v[i-1][j]-1;
                    }
                }else{
                    if(i==1){
                        c[i][j]=a[v[i][j-1]+1];
                        v[i][j]=v[i][j-1]+1;
                    }else{
                        c[i][j]=a[v[i-1][j]+1];
                        v[i][j]=v[i-1][j]+1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]==t){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}




















