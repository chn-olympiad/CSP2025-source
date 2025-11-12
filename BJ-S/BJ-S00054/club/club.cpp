#include<bits/stdc++.h>
#define int long long
void read(int &x){
    x=0;bool neg=0;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')neg=1;c=getchar();}
    while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(neg)x=-x;
}
#define se second
#define fi first
#define read2(x,y) read(x),read(y)
#define read3(x,y,z) read2(x,y),read(z)
using namespace std;
int n,ans,a[100005][3];
int id[100005];
void slv(){
    ans=0;
    read(n);
    for(int i=1;i<=n;i++)id[i]=0;
    // cout<<n<<endl;
    priority_queue<int>q[3];
    int cnt[3]={0,0,0};
    for(int i=1;i<=n;i++){
        read3(a[i][0],a[i][1],a[i][2]),ans+=max({a[i][0],a[i][1],a[i][2]});
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
            q[0].push({max(a[i][1],a[i][2])-a[i][0]});
            cnt[0]++;
        }
        else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
            q[1].push({max(a[i][0],a[i][2])-a[i][1]});
            cnt[1]++;
        }
        else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]){
            q[2].push({max(a[i][0],a[i][1])-a[i][2]});
            cnt[2]++;
        }
    }
    if(cnt[0]>n/2){
        while(cnt[0]>n/2){
            ans+=q[0].top();
            cnt[0]--;
            q[0].pop();
        }
    }
    else if(cnt[1]>n/2){
        while(cnt[1]>n/2){
            ans+=q[1].top();
            cnt[1]--;
            q[1].pop();
        }
    }
    else if(cnt[2]>n/2){
        while(cnt[2]>n/2){
            ans+=q[2].top();
            cnt[2]--;
            q[2].pop();
        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;read(T);while(T--)
    slv();
}