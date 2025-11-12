#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int yy[510];
int ans=0;
//int cnt=0;//num of was_killed
int c[510];

void dfs(int x,int y,int z){//x day;y was killed;z success
    if(x>n){
        if(z==m){
            ans++;
        }return ;
    }
    if(y>=c[x]){

        dfs(x+1,y+1,z);
        return;
    }
    if(yy[x]==1){
        dfs(x+1,y+1,z);
        return ;
    }
    dfs(x+1,y,z+1);
    return ;

}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;

    cin>>s;

    for(int i=1;i<=n;i++){
        yy[i]=s[i-1]-'0';
    }

    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;


}
