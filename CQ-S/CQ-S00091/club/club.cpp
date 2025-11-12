#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int t;
int n;
ll ans;
struct node{
    int f,s,t;
};
node a[100005];
bool cmp(node x,node y){
    return x.f>y.f;
}
void dfs(int x,int c1,int c2,int c3,ll res){
    if(x>n){
        if(c1>n/2||c2>n/2||c3>n/2){
            return;
        }
        ans=max(ans,res);
        return;
    }
    if(c1+1<=n/2){
        dfs(x+1,c1+1,c2,c3,res+a[x].f);
    }
    if(c2+1<=n/2){
        dfs(x+1,c1,c2+1,c3,res+a[x].s);
    }
    if(c3+1<=n/2){
        dfs(x+1,c1,c2,c3+1,res+a[x].t);
    }
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	    cin>>n;
        ans=0;
        int f=0;
        for (int i = 1; i <= n; i++) {
            cin>>a[i].f>>a[i].s>>a[i].t;
            if(a[i].s!=0||a[i].t!=0){
                f=1;
            }
        }
        if(!f){
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[i].f;
            }
            cout<<ans<<"\n";
            continue;
        } else {
            dfs(1,0,0,0,0);
            cout<<ans<<"\n";
        }
	}
	return 0;
}