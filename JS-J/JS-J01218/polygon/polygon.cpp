#include<bits/stdc++.h>
using namespace std;
int a,visited[5001],choose[5001],len[5001],counter=0;
int polyyes(int v){
    int maxn=0,sum=0;
    for(int i=1;i<=v;i++){
        sum+=len[choose[i]];
        if(maxn<len[choose[i]]){
            maxn=len[choose[i]];
        }
    }
    if(sum>2*maxn){
        return 1;
    }
    return 0;
}
void look(int u){
    if(polyyes(u)){
        counter++;
    }
}
void dfs(int step,int depth){
    int i;
    for(int i=choose[step-1]+1;i<=a;i++){
        if(!visited[i]){
            choose[step]=i;
            visited[i]=1;
            if(step==depth){
                look(step);
            }
            else{
                dfs(step+1,depth);
            }
            visited[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>len[i];
    }
    for(int i=3;i<=a;i++){
        memset(visited,0,sizeof(visited));
        memset(choose,0,sizeof(choose));
        dfs(1,i);
    }
    cout<<counter;
    return 0;
}
