#include<iostream>
#include<cstdio>
using namespace std;
int a[500005],n,k,ans;
bool b[5005][5005],f[500005];
void dfs(int i,int cnt){
    ans=max(ans,cnt);
    for(int j=i;j<=n;j++){
        if(f[j]==false&&b[i][j]){
            f[j]=true;
            dfs(j,cnt+1);
            f[j]=false;
        }
        else if(f[j]==false){
            dfs(j+1,cnt);
        }
    }
}
int main(){
    f[0]=true;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i]^a[j]==k){
                b[i][j]=true;
                b[j][i]=true;
            }
        }
    }
    dfs(0,0);
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            //if(b[i][j]==true){
                f[i]=max(f[i],f[j]+b[i][j]);
            //}
        }
    }*/
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
