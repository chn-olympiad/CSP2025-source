#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],ans;
vector<int> v[4];
bool cmp1(int x,int y){
    return min(a[x][1]-a[x][2],a[x][1]-a[x][3])<=min(a[y][1]-a[y][2],a[y][1]-a[y][3]);
}
bool cmp2(int x,int y){
    return min(a[x][2]-a[x][1],a[x][2]-a[x][3])<=min(a[y][2]-a[y][1],a[y][2]-a[y][3]);
}
bool cmp3(int x,int y){
    return min(a[x][3]-a[x][1],a[x][3]-a[x][2])<=min(a[y][3]-a[y][1],a[y][3]-a[y][2]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        v[1].clear();
        v[2].clear();
        v[3].clear();
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) ans+=a[i][1],v[1].push_back(i);
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) ans+=a[i][2],v[2].push_back(i);
            else ans+=a[i][3],v[3].push_back(i);
        }
        if((int)v[1].size()>n/2){
            sort(v[1].begin(),v[1].end(),cmp1);
            for(int i=0;i<(int)v[1].size()-n/2;i++) ans-=min(a[v[1][i]][1]-a[v[1][i]][2],a[v[1][i]][1]-a[v[1][i]][3]);
        }else if((int)v[2].size()>n/2){
            sort(v[2].begin(),v[2].end(),cmp2);
            for(int i=0;i<(int)v[2].size()-n/2;i++) ans-=min(a[v[2][i]][2]-a[v[2][i]][1],a[v[2][i]][2]-a[v[2][i]][3]);
        }else if((int)v[3].size()>n/2){
            sort(v[3].begin(),v[3].end(),cmp3);
            for(int i=0;i<(int)v[3].size()-n/2;i++) ans-=min(a[v[3][i]][3]-a[v[3][i]][1],a[v[3][i]][3]-a[v[3][i]][2]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
