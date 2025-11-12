#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
bool fa=1;
struct s{
    int a1,a2,a3;
}a[100005];
void dfs(int sum,int w,int p1,int p2,int p3){//n<=15 20pts
    //cout<<p1<<' '<<p2<<' '<<p3<<\n;
    if(w==n){
        ans=max(ans,sum);
        return ;
    }
    if(p1+1<=n/2) dfs(sum+a[w+1].a1,w+1,p1+1,p2,p3);
    if(p2+1<=n/2) dfs(sum+a[w+1].a2,w+1,p1,p2+1,p3);
    if(p3+1<=n/2) dfs(sum+a[w+1].a3,w+1,p1,p2,p3+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        fa=1;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            if(a[i].a2!=0||a[i].a3!=0){
                fa=0;
            }
        }
        if(fa){
            for(int i=1;i<=n;i++){
                ans+=a[i].a1;
            }
            cout<<ans<<"\n";
            continue;
        }
        dfs(0,0,0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}

/*
wo3 zen3 mo sha2 ye3 bu2 hui4 a,gan3 jue2 bai2 xue2 le yi4 nian2
*/