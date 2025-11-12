#include<bits/stdc++.h>
using namespace std;
int t,vis[5],stu[100000+10][3],maxx[100000+10][3],n;
void dfs(int x,int y,int d,int n){
    d+=stu[x][y]; 
    if(x==n+1){
        return;
    }
    
    maxx[x][y]=max(maxx[x][y],d);
    for(int i=1;i<=3;i++){
        if(vis[i]+1<=n/2){
            vis[i]++;
            dfs(x+1,i,d,n);
            vis[i]--;
        }
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            stu[i][1]=0,stu[i][2]=0,stu[i][3]=0;
            maxx[i][1]=0,maxx[i][2]=0,maxx[i][3]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>stu[i][1]>>stu[i][2]>>stu[i][3];
        }
        for(int i=1;i<=3;i++)vis[i]=0;
        for(int i=1;i<=3;i++){
            vis[i]++;
            dfs(1,i,0,n);
            vis[1]=0,vis[2]=0,vis[3]=0;
        }
        int maxn=0;
        for(int i=1;i<=3;i++){
            maxn=max(maxn,maxx[n][i]);
        }
        cout<<maxn<<endl;
    }
	return 0;
}

