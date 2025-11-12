#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010],s[5010];
bool v[5010];
void dfs(int step,int mo){
    if(step==mo+1){
        int Max=0,cnt=0;
        for(int i=1;i<=mo;i++){
            cnt+=s[i];
            Max=max(Max,s[i]);
        }
        if(cnt>Max*2) ans++;
    }
    else{
        for(int i=1;i<=n;i++){
            if(v[i]==0&&a[i]>=s[step-1]){
                v[i]=1;
                s[step]=a[i];
                dfs(step+1,mo);
                v[i]=0;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(1,i);
    }
    cout<<ans;
    return 0;
}