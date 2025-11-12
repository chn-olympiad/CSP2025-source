#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1];
    int b[n+1][m+1];
    int t;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+m*n+1);
    stack<int>k;
    for(int i=1;i<=n*m;i++){
        k.push(a[i]);
    }
    for(int i=1;i<=n*m;i++){
        a[i]=k.top();
        k.pop();
    }
    if(n==1 && m==1){
        cout<<1<<" "<<1;
        return 0;
    }
    int s=1;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=m;i++){
            if(j%2!=0){
                b[i][j]=a[s];
            }else{
                b[n-i+1][j]=a[s];
            }
            s++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==t){
                cout<<j<<" "<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}




