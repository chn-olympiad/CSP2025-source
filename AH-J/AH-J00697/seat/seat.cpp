#include<bits/stdc++.h>
using namespace std;
int a[105],st[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int all=n*m;
    for(int i=1;i<=all;i++){
        cin>>a[i];
    }
    int score=a[1],mx=1,nx=1;
    sort(a+1,a+all+1,cmp);
    for(int i=1;i<=all;i++){
        if(((i-1)/n)%2==0){
            st[nx][mx]=a[i];
            nx++;
        }else{
            nx--;
            st[nx][mx]=a[i];
        }
        if(nx==n+1||nx==1){
            mx++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st[i][j]==score){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
