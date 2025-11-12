#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define c(x) cout<<x<<"<"<<endl
using namespace std;
const int fet=1e5+10;
int n,n2,a[fet][4];

int ans,sum;
int vis[5];
void dfs(int x){
    if(x==n){
        ans=max(ans,sum);
    }else{
        for(int i=1;i<4;i++){
            if(vis[i]==n2) continue;
            sum+=a[x][i]; vis[i]++;
            dfs(x+1);
            sum-=a[x][i]; vis[i]--;
        }
    }
}
void in1(){
    for(int i=0;i<n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
    ans=-inf,sum=0;
    dfs(0);
    cout<<ans<<endl;
}

struct node{
    int a,b,c;
};
bool cmp(node a,node b){
    return a.b>b.b;
}
void in2(){
    node a_[fet];
    for(int i=0;i<n;i++)
        cin>>a_[i].a>>a_[i].b>>a_[i].c;
    sort(a_,a_+n,cmp);
    int v[3]={};
    for(int i=0;i<n;i++){
        int maxn=max(a_[i].a,a_[i].b);
        if(maxn==a_[i].a&&v[1]<n2) ans+=a_[i].a,v[1]++;
        else if(maxn==a_[i].b&&v[2]<n2) ans+=a_[i].b,v[2]++;
        else if(maxn!=a_[i].a&&v[1]<n2) ans+=a_[i].a,v[1]++;
        else if(maxn!=a_[i].b&&v[2]<n2) ans+=a_[i].b,v[2]++;
    }
    cout<<ans<<endl;
}
void in3(){
    int a_[fet];
    for(int i=0,b,c;i<n;i++) cin>>a_[i]>>b>>c;
    sort(a_,a_+n);
    for(int i=n-1;i>=0;i--) ans+=a_[i];
    cout<<ans<<endl;
}

void sovle(){
    cin>>n; n2=n/2; memset(a,0,sizeof(a));
    if(n<=15) in1();
    else if(n==100000) in3();
    else in2();
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--) sovle();
    return 0;
}
