#include <bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m,R,num,mum,il=1,jl=1;
void dan(){
    bool flag=true;
    for(int i=1;i<=n;i++){
        bool d=true;
        for(int j=1;j<=m;j++){
            if(i==n && j==m) continue;
            if(a[i][j] > R){
                num=i,mum=j;
                flag=false;
                d=false;
                break;
            }
        }
        if(!d) break;
    }
    if(!flag) a[num][mum]=0;
    else return;
    if(il%2==1){
        jl++;
        if(jl==m) il++;
    }else{
        jl--;
        if(jl==1) il++;
    }
}
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m>>R;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++){
            if(i==n && j==m) continue;
            cin>>a[i][j];
        }
    }
    dan();
    if(il%2==1) cout<<jl+1<<" "<<il;
    if(il%2==0) cout<<m-jl<<" "<<il;
    return 0;
}
