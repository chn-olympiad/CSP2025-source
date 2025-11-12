#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5001],b[5001];
bool used[5001];
void dfs(int now,int m,int sum){
    if(now==m+1){
        sort(b,b+now+1);
        for(int i=1;i<=now;i++)cout<<b[i]<<' ';
        cout<<endl;
        if(sum>=2*b[now])ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            b[now]=a[i];
            used[i]=true;
            dfs(now+1,m,sum+b[now]);
            used[i]=false;
        }
       
    }
    return;
}
int A(int x){
    int sum=1;
    for(int i=x;i>=1;i--)sum*=i;
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=3;i<=n;i++){
        memset(used,false,sizeof(used));
        dfs(1,i,0);
        ans/=A(i);
        cout<<ans<<' ';
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}