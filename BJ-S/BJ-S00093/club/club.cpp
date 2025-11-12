#include <bits/stdc++.h>
using namespace std;
int T,n,ans,cnt;
struct Node{
    int a,b,c;
};
Node stu[107891];
int pre[107891],vis[107891];
bool cmp(Node a, Node b){
    return a.a>b.a;
}

bool isFail(){
    int cntA=0,cntB=0,cntC=0;
    for(int i = 1; i <= n; i++){
        if(pre[i]==1){
            cntA++;
        }else if(pre[i]==2){
            cntB++;
        }else if(pre[i]==3){
            cntC++;
        }
    }
    return (cntA<=n/2)&&(cntB<=n/2)&&(cntC<=n/2);
}
void Value(){
    int sumA=0,sumB=0,sumC=0;
    for(int i = 1; i <= n; i++){
        if(pre[i]==1){
            sumA+=stu[i].a;
        }else if(pre[i]==2){
            sumB+=stu[i].b;
        }else if(pre[i]==3){
            sumC+=stu[i].c;
        }
    }
    ans=max(ans,sumA+sumB+sumC);
}
void dfs(int depth){
    if(depth>n){
        if(isFail()) Value();
        return;
    }
    for(int i = 1; i <= 3; i++){
        pre[depth]=i;
        dfs(depth+1);
        pre[depth]=0;
    }
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(stu,0,sizeof(stu));
        cin>>n;
        for(int i = 1; i <= n;i ++){
            cin>>stu[i].a>>stu[i].b>>stu[i].c;
            if(stu[i].b==0&&stu[i].c==0) cnt++;
        }
        if(cnt==n){
            sort(stu+1,stu+n+1,cmp);
            int sum=0;
            for(int i = 1; i <= n/2; i++) sum+=stu[i].a;
            cout<<sum<<endl;
            continue;
        }
        ans=-1e9;
        memset(pre,0,sizeof(pre));
        memset(vis,0,sizeof(vis));
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
