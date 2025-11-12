#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[5001];
int num[5001];
int ans=0;
void dfs(int dep,int num[],int cnt,int last){
    if(n-last<dep-cnt+1)
        return ;
    if(cnt>dep){
        ll sum=0;
        int maxn=0;
        for(int i=1;i<=dep;i++){
            sum+=num[i];
            maxn=max(num[i],maxn);
        }
        if(sum>maxn*2)
            ans++;
        return ;
    }
    for(int i=last+1;i<=n;i++){
        num[cnt]=a[i];
        dfs(dep,num,cnt+1,i);
        num[cnt]=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int k=3;k<=n;k++){
        dfs(k,num,1,0);
    }
    cout<<ans<<'\n';
    return 0;
}
