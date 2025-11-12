#include<bits/stdc++.h>
using namespace std;
const int N=3E5+10;
struct node{
    int x;
    int num,pro;
}a[N];
int n;
int tot;
bool vis[N];
int b[5];
bool cmp(node n1,node n2){
    return n1.x>n2.x;
}
int an;
struct node1{
    int x,y,z;
}ay[N];
void dfs(int i,int sum,int cnta,int cntb,int cntc){
    if(i==n+1){
        an=max(an,sum);
        return;
    }
    if(cnta<(n/2))dfs(i+1,sum+ay[i].x,cnta+1,cntb,cntc);
    if(cntb<(n/2))dfs(i+1,sum+ay[i].y,cnta,cntb+1,cntc);
    if(cntc<(n/2))dfs(i+1,sum+ay[i].z,cnta,cntb,cntc+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        tot=0;
        int flag=1;
        for(int i=1;i<=n;i++){
            cin>>ay[i].x>>ay[i].y>>ay[i].z;
            a[++tot]={ay[i].x,i,1};
            a[++tot]={ay[i].y,i,2};
            a[++tot]={ay[i].z,i,3};
            if(ay[i].y!=0||ay[i].z!=0)flag=0;
        }
        if(flag){
            sort(a+1,a+(n*3)+1,cmp);
            int ans=0;
            for(int i=1;i<=(n/2);i++)ans+=a[i].x;
            cout<<ans;
        }
        else if(n<=30){
            an=0;
            dfs(1,0,0,0,0);
            cout<<an;
            continue;
        }
        else{
            memset(vis,0,sizeof(vis));
            memset(b,0,sizeof(b));
            sort(a+1,a+tot+1,cmp);
            int ans=0,cnt=0;
            for(int i=1;i<=(3*n);i++){
                if(vis[a[i].num])continue;
                if(b[a[i].pro]==(n/2))continue;
                vis[a[i].num]=1;
                b[a[i].pro]++;
                ans+=a[i].x;
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
