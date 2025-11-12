#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105];
bool cmp(int asd,int qwe){
    return asd>qwe;
}
void dfs(int x,int y,int step){
    if(step==r){
        cout<<y<<" "<<x;
        return;
    }
    if(y%2==1 && x!=n)dfs(x+1,y,step+1);
    else if(y%2==0 && x!=1)dfs(x-1,y,step+1);
    else if(y%2==1 && x==n)dfs(x,y+1,step+1);
    else if(y%2==0 && x==1)dfs(x,y+1,step+1);
    return;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
            break;
        }
    }
    dfs(1,1,1);
    return 0;
}
