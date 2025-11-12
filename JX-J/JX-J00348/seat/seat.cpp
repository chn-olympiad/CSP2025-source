#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int ans[110][110]={0};

bool cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int zong=n*m,score;
    for(int i=1;i<=zong;i++){
        cin>>a[i];
        if(i==1) score=a[i];
    }
    sort(a+1,a+zong+1,cmp);
    int tot=1,now=1;//di ji ge
    int x=1,y=1;//x: hang y:lie

    while(tot<=zong){
        ans[x][y]=a[tot];
        if(y%2==1){
            if(x==n){
                y++;
                tot++;
            }
            else{
                x++;
                tot++;
            }
        }
        else if(y%2==0){
            if(x==1){
                y++;
                tot++;
            }
            else{
                x--;
                tot++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==score){
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
