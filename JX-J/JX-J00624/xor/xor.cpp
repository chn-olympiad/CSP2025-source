#include<bits/stdc++.h>
using namespace std;
int n,flag,a[500001],h[500001],k,ans;
void dfs(int deep,int cnt,int now){
    if(deep>n||now>n){
        ans=max(ans,cnt);
        return;
    }
    if(a[now]==k){
        dfs(deep+1,cnt+1,now+1);
        return;
    }
    for(int j=now+1;j<=n;j++){
        if((h[j]^h[now-1])==k){
            dfs(deep+1,cnt+1,j+1);
            break;
        }
    }
    dfs(deep+1,cnt,now+1);
    return;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d%d",&n,&k,&a[1]);
    h[1]=a[1];
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
        h[i]=a[i]^h[i-1];
        if(a[i]==0&&flag==0)flag=1;
        else if(a[i]>1)flag=2;
    }
    if(flag==0){
        printf("%d",n/2);
    }else if(flag==1){
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
                else if(a[i]==1&&a[i+1]==0||a[i]==0&&a[i+1]==1)i++,ans++;
            }
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
                else if(a[i]==1&&a[i+1]==1)i++,ans++;
            }
        }
        printf("%d",ans);
    }else{
        dfs(1,0,1);
        printf("%d",ans);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
