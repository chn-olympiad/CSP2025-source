#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}p[100005];
long long ans;
int t,n;
void dfs(int cur,long long s,int cnt1,int cnt2,int cnt3){
    if(cur>n){
         ans=max(s,ans);
         return;
    }
    if(cnt1<n/2){
        dfs(cur+1,s+p[cur].a,cnt1+1,cnt2,cnt3);
    }
    if(cnt2<n/2){
        dfs(cur+1,s+p[cur].b,cnt1,cnt2+1,cnt3);
    }
    if(cnt3<n/2){
        dfs(cur+1,s+p[cur].c,cnt1,cnt2,cnt3+1);
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].a >>p[i].b >>p[i].c;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}

