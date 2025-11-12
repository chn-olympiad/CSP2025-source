#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int n,m,R;
int a[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("sear.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        int u;
        scanf("%d",&u);
        if(i==1) R=u;
        q.push(u);
    }
    int cnt=1;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                a[i][j]=q.top();
                if(a[i][j]==R){
                    printf("%d %d",j,i);
                    return 0;
                }
                q.pop();
            }
        }
        if(j%2==0){
            for(int i=n;i>=1;i--){
                a[i][j]=q.top();
                if(a[i][j]==R){
                    printf("%d %d",j,i);
                    return 0;
                }
                q.pop();
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
