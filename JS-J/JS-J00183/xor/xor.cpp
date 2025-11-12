#include<bits/stdc++.h>
using namespace std;
int n,k,sum;
int a[1010];
int ans[1010][1010];
bool vis[1010][1010];
int xx[1000010],yy[1000010],ansi=1,maxi;
void sxor(int x,int y){
    vis[x][y]=1;
    if(x>y) return;
    if(x==y){
        vis[x][y]=1;
        ans[x][y]=a[y];
    }
    if(vis[x][y-1]==0){
        vis[x][y-1]=1;
        sxor(x,y-1);
    }
    int answer=ans[x][y-1]^a[y];
    if(answer==k){
        xx[ansi]=x;
        yy[ansi]=y;
        ansi++;
    }
    ans[x][y]=answer;
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            sxor(i,j);
        }
    }
    for(int i=1;i<ansi;i++){
        if(xx[i]<=maxi) continue;
        else{
            sum++;
            maxi=yy[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}
