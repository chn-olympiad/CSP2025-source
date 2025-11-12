#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m,a[15][15],b[105],t;
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
    t=b[1];
    sort(b+1,b+1+(n*m),cmp);
    int cnt=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                a[j][i]=b[cnt];
                cnt++;
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                a[j][i]=b[cnt];
                cnt++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==t){
                cout<<j<<" "<<i;
                return 0;
            }
            //cout<<a[i][j];
        }
        //cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
