#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}f[100003];
int t,n,ans;
bool cmpa(node s1,node s2){
    return s1.a>s2.a;
}
bool cmpb(node s1,node s2){
    return s1.b>s2.b;
}
bool cmpc(node s1,node s2){
    return s1.c>s2.c;
}
void dfs(int it,int ac,int bc,int cc,int tmp){
    if(it==n){
        ans=max(tmp,ans);
        return;
    }
    if(ac<(n>>1)) dfs(it+1,ac+1,bc,cc,tmp+f[it+1].a);
    if(bc<(n>>1)) dfs(it+1,ac,bc+1,cc,tmp+f[it+1].b);
    if(cc<(n>>1)) dfs(it+1,ac,bc,cc+1,tmp+f[it+1].c);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;ans=0,i++){
        bool flaga=0,flagb=0,flagc=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>f[j].a>>f[j].b>>f[j].c;
            if(f[j].b||f[j].c) flaga=1;
            if(f[j].a||f[j].c) flagb=1;
            if(f[j].a||f[j].b) flagc=1;
        }
        if(!flaga){
            sort(f+1,f+n+1,cmpa);
            for(int j=1;j<=(n>>1);j++) ans+=f[j].a;
        }
        else if(!flagb){
            sort(f+1,f+n+1,cmpb);
            for(int j=1;j<=(n>>1);j++) ans+=f[j].b;
        }
        else if(!flagc){
            sort(f+1,f+n+1,cmpc);
            for(int j=1;j<=(n>>1);j++) ans+=f[j].c;
        }
        else dfs(0,0,0,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
