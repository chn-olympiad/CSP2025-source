#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],c[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num,cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    num=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
        b[n*m-i+1]=a[i];
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            cnt++;
            if(j%2==0)
                c[n-i+1][j]=b[cnt];
            else
                c[i][j]=b[cnt];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]==num){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
