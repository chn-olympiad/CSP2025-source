#include<bits/stdc++.h>
#define maxn 500010
#define maxl 22
using namespace std;
int k2[maxl];
int n,k,ans,cnt;
int a[maxn];
int a2[maxn][maxl];
int len[maxn];
int k2len;
void chanfor2(int n){
    for(int i=1;i<=n;i++){
        int j=0;
        while(a[i]>0){
            a2[i][++j]=a[i]%2;
            a[i]/=10;
        }
        len[i]=j;
    }
    return;
}
bool judge(int l,int r){
    int tend[maxl]={0};
    for(int i=l;i<=r;i++){
        for(int j=1;j<=len[i];j++){
            if(tend[j]==a2[i][j]){
                tend[j]=0;
            }else if(tend[j]!=a2[i][j]){
                tend[j]=1;
            }
        }
    }
    for(int i=1;i<=k2len;i++){
        if(tend[i]!=k2[i]){
            return 0;
        }
    }
    return 1;
}
void dfs(int l,int r){
    if(l>=n||r>n){
        return;
    }
    if(judge(l,r)){
        cnt++;
        dfs(l+1,r+1);
    }else if(r==n){
        dfs(l+1,l+2);
    }else{
        dfs(l,r+1);
    }
    // int count=cnt;
    ans=max(cnt,ans);
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("or.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
        }
        printf("%d",ans);
        return 0;
    }
    chanfor2(n);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=len[i];j++){
    //         cout<<a2[i][j];
    //     }
    //     cout<<endl;
    // }
    int i=0;
    while(k>0){
        k2[++i]=k%2;
        k/=10;
    }
    k2len=i;
    cout<<judge(1,2);
    dfs(0,0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}