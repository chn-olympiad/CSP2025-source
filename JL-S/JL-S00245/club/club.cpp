#include<bits/stdc++.h>
using namespace std;
struct nude{
    int x,y,z;
}a[100100];
int n;
int maxx=-1;
int cmp(nude aa,nude bb){
    return aa.y>bb.y;
}
void dfs(int sum,int wh,int x1,int x2,int x3){
    if(wh==n+1){
        maxx=max(maxx,sum);
        return ;
    }
    if(x1<n/2) dfs(sum+a[wh].x,wh+1,x1+1,x2,x3);
    if(x2<n/2) dfs(sum+a[wh].y,wh+1,x1,x2+1,x3);
    if(x3<n/2) dfs(sum+a[wh].z,wh+1,x1,x2,x3+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        if(n>30){
            sort(a+1,a+n+1,cmp);
            int sum=0;
            for(int i=1;i<=n/2;i++){
                sum+=a[i].y;
            }
            cout<<sum<<endl;
            continue;
        }
        maxx=-1;
        dfs(0,1,0,0,0);
        cout<<maxx<<endl;
    }
    return 0;
}
