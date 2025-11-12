#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],maxn,f;
void dfs(int x,int s,int ca,int cb,int cc){
    if(ca>n/2||cb>n/2||cc>n/2){
        return;
    }
    if(ca+cb+cc>n){
        return;
    }
    if(x>n){
        maxn=max(maxn,s);
    }
    dfs(x+1,s+a[x],ca+1,cb,cc);
    dfs(x+1,s+b[x],ca,cb+1,cc);
    dfs(x+1,s+c[x],ca,cb,cc+1);
}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0 || c[i]!=0){
                f=1;
            }
        }
        if(f==0 &&n>=200){
            sort(a+1,a+n+1,cmp);
            int ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<maxn<<endl;
    }
    return 0;
}
