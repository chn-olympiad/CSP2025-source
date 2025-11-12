#include<bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
const int N=1e5+5;
int T,n;
int s[N][5];
ll ans=-1,num,mans=-1;
int vis[N];
int q[5];
void dfs(int x,int c){
    if(q[c]>n/2) return;
    if(x==n){
        ans=max(ans,num);
        return;
    }
    f(i,1,3){
        q[i]++;
        num+=s[x+1][i];
        dfs(x+1,i);
        num-=s[x+1][i];
        q[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        f(i,1,n) cin>>s[i][1]>>s[i][2]>>s[i][3];
        f(i,1,3){
            q[i]=1;
            num=s[1][i];
            dfs(1,i);
            num=0;
            mans=max(mans,ans);
            ans=0;
            f(i,1,3) q[i]=0;
        }
        cout<<mans<<endl;
        mans=0;
    }
    return 0;
}
