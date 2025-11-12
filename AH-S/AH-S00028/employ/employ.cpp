#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
string s;
int a[105];
int vis[105];
int dfs(int pos){
    if(pos==n+1){
        int ps=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(ps>=a[i]){
                ps++;
            }else{
                cnt++;
            }
        }
        return cnt>=m;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            sum+=dfs(pos+1);
            vis[i]=0;
        }
    }
    return sum;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cout<<1;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<dfs(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
