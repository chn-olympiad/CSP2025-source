#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int vis[3]={0,0,0};
int x1,x2,x3;
int num,maxn,t;
int choice(int m){
for(int i=1;i<=m;i++){
        num=max(a[i][1],a[i][2]);
        t=max(num,a[i][3]);
        if(t==a[i][3]) x3++;
        if(t==a[i][2]) x2++;
        else x1++;
        maxn=t;
        cout<<maxn;

    if(x1>=m/2){
        a[i][1]=-1;
    }

if(x2>=m/2){
        a[i][2]=-1;
    }
if(x3>=m/2){
        a[i][3]=-1;
    }
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,m;
    cin>>n>>m;
    while(n--){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }

    }
     choice(m);
     fclose(stdin);
     fclose(stdout);
}
return 0;
}
