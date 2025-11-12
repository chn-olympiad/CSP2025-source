#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,dp[N],l[3*N],m,f[N];
struct nd{
    int a,b,c;
} q[N];

int dfs(int p,int c1,int c2,int c3,int sum){
    //cout<<p<<" "<<sum<<endl;
    if(p==0)return sum;
    //if(dp[p]>sum)return dp[p];
    //cout<<p<<" "<<sum<<endl;
    if(c1>=n/2){
        return dp[p]=max(dfs(p-1,c1,c2+1,c3,sum+q[p].b),dfs(p-1,c1,c2,c3+1,sum+q[p].c));
    }
    if(c2>=n/2){
        return dp[p]=max(dfs(p-1,c1+1,c2,c3,sum+q[p].a),dfs(p-1,c1,c2,c3+1,sum+q[p].c));
    }
    if(c3>=n/2){
        return dp[p]=max(dfs(p-1,c1,c2+1,c3,sum+q[p].b),dfs(p-1,c1+1,c2,c3,sum+q[p].a));
    }
    return dp[p]=max(dfs(p-1,c1+1,c2,c3,sum+q[p].a),max(dfs(p-1,c1,c2+1,c3,sum+q[p].b),dfs(p-1,c1,c2,c3+1,sum+q[p].c)));
}
bool cmp(nd a,nd b){
    return a.c>b.c;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        cin>>n;
        int s1=0,s2=0;
        for(int i=1;i<=n;i++){
            cin>>q[i].a>>q[i].b>>q[i].c;/*l[++m]=q[i].a,l[++m]=a[i].b,l[++m]=q[i].c;*/
            s1+=q[i].a,s2+=q[i].b;
        }
        if(s1==0&&s2==0){
            sort(q+1,q+1+n,cmp);
            int s=0;
            for(int i=1;i<n/2;i++){
                s+=q[i].c;
            }
            cout<<s<<endl;
        }else {
            cout<<dfs(n,0,0,0,0)<<endl;
        }
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
