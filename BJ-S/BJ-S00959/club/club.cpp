#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int n;
int t;
int maxn=-1e5;
int dfs(int ans,int s1,int s2,int s3,int depth){
    maxn=max(maxn,ans);
    if(depth>n+1)return ans;
    int c1,c2,c3;
    if((s1+1)<=n/2)c1=dfs(ans+a[depth],s1+1,s2,s3,depth+1 );
    if((s2+1)<=n/2)c2=dfs(ans+b[depth],s1,s2+1,s3,depth+1 );
    if((s3+1)<=n/2)c3=dfs(ans+c[depth],s1,s2,s3+1,depth+1 );
    return max(c1,max(c2,c3));
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=-1e5;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n!=100000){
        int cmp=dfs(0,0,0,0,1);

        }else{
            sort(a+1,a+n+1);
            maxn=0;
            for(int i=n;i>n/2;i--){
                maxn+=a[i];
            }
        }
        cout<<maxn<<endl;
    }
    return 0;
}
