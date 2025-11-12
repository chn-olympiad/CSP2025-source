#include<bits/stdc++.h>
using namespace std;
int a[5003],n,ma,h,ah[5003],m;
long long ans;
void dfs(int num,int i,int ma,int h){
    if(i==m) return;
    queue<int> q;
    q.push(num);
    while(q.size()){
        int node=q.front();
        q.pop();
    }
}
void IF(int ma,int h){
    if(h > 2*ma) ans++;
    return;
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(n==3){
            ma=max(ma,a[i]);
            h+=a[i];
        }
    }
    //
    if(n<3){
        printf("%d",0);
        return 0;
    }
    if(n==3){
        if(h > 2*ma) printf("%d",1);
        else printf("%d",0);
    }
    //
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            m=i;
            dfs(j,1,0,0);
        }
    }
    return 0;
}
