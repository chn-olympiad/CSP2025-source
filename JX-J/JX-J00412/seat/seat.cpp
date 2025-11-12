#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    return x>y;
}
int main(){
    int n,m;
    cin>>n>>m;
    int s=1,c=1;
    int b[101]={},a[11][11]={};
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int q=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=b[c];
            c++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==q and n%2==0){
                if(m%2==0){
                    cout<<i<<" "<<m-j+1;
                }

            }
            else if(a[i][j]==q and n%2!=0){
                cout<<i<<" "<<j;
            }
        }
    }

    return 0;
}
