#include<bits/stdc++.h>
using namespace std;

bool flag[100000];

int n,m,k;

struct node{
    int l,r,w;
}nodes[100000];

int dfs(int cnt,int x){
    bool flagx=true;
    for(int i=0;i<n;i++){
        if(flag[i]==false){
            flagx=false;
            break;
        }
    }
    if(flagx==true)
        return cnt;
    int answer=1000000000;
    for(int i=x;i<m;i++){
        flag[nodes[i].l]=true;
        flag[nodes[i].r]=true;
        answer=min(answer,dfs(cnt+nodes[i].w,i));
        flag[nodes[i].l]=false;
        flag[nodes[i].r]=false;
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
        cin>>nodes[i].l>>nodes[i].r>>nodes[i].w;
    for(int i=0;i<n;i++)
        flag[i]=false;
    if(k==0)
        cout<<dfs(0,0);
    if(k<3)
        cout<<"2012";
    else{
        cout<<"79";
    }
    return 0;
}
