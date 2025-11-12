#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define mod 998224353
int n,a[514514],choice[114514],ans,used[114514],s[514514];
void print(int depth){
    int sum=0,maxx=INT_MIN;
    for(int i=1;i<=depth;i++){
        //cout<<choice[i]<<" ";
        sum=sum+a[choice[i]];
        maxx=max(maxx,a[choice[i]]);
    }
    //cout<<"\n";
    if(sum>2*maxx){
        ans=ans+1;
        ans%=mod;
    }
}
void dfs(int depth,int maxdepth){
    if(depth>maxdepth){
        print(maxdepth);
    }else{
        for(int i=choice[depth-1];i<=n;i++){
            if(!used[i]){
                used[i]=1;
                choice[depth]=i;
                dfs(depth+1,maxdepth);
                used[i]=0;
            }
        }
    }
}
bool cmp(const int a,const int b){
return a<b;}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    choice[0]=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=3;i<=n;i++){
        dfs(1,i);
    }
    cout<<ans<<endl;
    return 0;
}
