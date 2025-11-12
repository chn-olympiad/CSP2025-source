#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int n,m,R;
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x,int y,int f,int cnt){
    int nx=x,ny=y,nf=f;
    //cout<<x<<" "<<y<<" "<<f<<" "<<cnt<<" "<<a[cnt]<<endl;
    if(a[cnt]==R){
        cout<<x<<" "<<y<<endl;
        return ;
    }
    ny+=f;
    if(ny>m){
        nf=-1;
        ny--;
        nx++;
    }
    if(ny<1){
        nf=1;
        ny++;
        nx++;
    }
    dfs(nx,ny,nf,cnt+1);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++){
        cin>>a[i];
        R=a[1];
    }
    sort(a+1,a+1+l,cmp);
    dfs(1,1,1,1);
    return 0;
}
