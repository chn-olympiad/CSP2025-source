#include <bits/stdc++.h>

using namespace std;
int a[200001][4];
int visit[4];
int n;
int dfs(int x,int y){
    if(x>=n)
        return a[x][y];
    int maxx=0;
    for(int i=1;i<=3;i++){
        if(visit[i]<n/2){
            visit[i]++;
            maxx=max(maxx,a[x][y]+dfs(x+1,i));
            visit[i]--;
        }
    }
    return maxx;
}
void club(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    int maxx=0;
    cout<<dfs(0,1)<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        club();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
