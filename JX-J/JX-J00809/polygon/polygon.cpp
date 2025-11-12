#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int e=0;
void dfs(int x,int y,int z){
    if(y>2*z) e++;
 //   cout<<y<<" "<<z<<endl;
    for(int i=x+1;i<=n;i++){
        int ty=max(z,a[i]),tx=y+a[i];
        dfs(i,tx,ty);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            for(int k=1;k<j;k++){
                int y=max(a[i],max(a[j],a[k])),x=a[i]+a[j]+a[k];
                dfs(i,x,y);
            }
        }
    }
    cout<<e;
    return 0;
}
