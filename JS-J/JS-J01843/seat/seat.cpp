#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int dir[10][2]={1,0,0,1,-1,0,0,1};
int p[1000005];
bool cmp(int a,int b){
    return a>b;
}
void DFS(int r,int c,int k,int cnt){
    int dr=r+dir[k][0],dc=c+dir[k][1];
    if(1<=dr&&dr<=n&&1<=dc&&dc<=m&&p[cnt]==t){
        cout<<dc<<" "<<dr;
        return;
    }
    else if(dr>n||dr<1){
        if(dc!=m){
            k++;
            k%=4;
            dr=r+dir[k][0],dc=c+dir[k][1];
            if(1<=dr&&dr<=n&&1<=dc&&dc<=m&&p[cnt]==t){
                cout<<dc<<" "<<dr;
                return;
            }
            k++;
            k%=4;
            DFS(dr,dc,k%4,cnt+1);
        }
        else{
            cout<<dc<<" ";
            if(dr>n) cout<<n;
            else cout<<1;
            return;
        }
    }
    else{
        DFS(dr,dc,k%4,cnt+1);
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++){
        cin>>p[i];
        if(i==1) t=p[i];
    }
    sort(p+1,p+k+1,cmp);
    DFS(0,1,0,1);
    return 0;
}
