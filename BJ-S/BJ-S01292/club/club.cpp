#include <bits/stdc++.h>

using namespace std;

int c1[100005],c2[100005];
struct chapoint{
    int idx, c;
    friend bool operator<(chapoint a,chapoint b){
        return a.c>b.c;
    }
} d1[100005],d2[100005];
bool vis[100005];
priority_queue<int> q1,q2;
int dp[205][205][205];

void work1(int n,int sum){
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n/2;j++){
            for(int k=0;k<=n/2;k++){
                dp[i][j+1][k]=max(dp[i-1][j][k]+c1[i],dp[i-1][j+1][k]);
                dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+c2[i]);
            }
        }
    }
    int ans=sum;
    int maxn=-0x3f3f3f3f;
    for(int j=0;j<=n/2;j++){
        for(int k=0;k<=n/2;k++){
            if(j+k>=n/2){
                maxn=max(maxn,dp[n][j][k]);
            }
        }
    }
    cout<<ans+maxn<<endl;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        int n;
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            sum+=a;
            c1[i]=b-a;
            d1[i].c=c1[i];
            d1[i].idx=i;
            c2[i]=c-a;
            d2[i].c=c2[i];
            d2[i].idx=i;
        }
        if(n<=200){
            work1(n,sum);
            continue;
        }
        int cnt=0;
        int p1=1,p2=1;
        int cnt1=0,cnt2=0;
        sort(d1+1,d1+n+1);
        sort(d2+1,d2+n+1);
        for(int i=1;i<=n/2;i++){
            if(d1[p1].c>=d2[p2].c){
                cnt+=d1[p1].c;
                q1.push(d2[p2].c-d1[p1].c);
                vis[d1[p1].idx]=true;
                while(vis[d1[p1].idx])p1++;
                cnt1++;
            }
            else{
                cnt+=d2[p2].c;
                q2.push(d1[p1].c-d2[p2].c);
                vis[d2[p2].idx]=true;
                while(vis[d2[p2].idx])p2++;
                cnt2++;
            }
        }
        while(d1[p1].c>0&&d2[p2].c>0&&cnt1<n/2&&cnt2<n/2){
            if(d1[p1].c>=d2[p2].c){
                cnt+=d1[p1].c;
                q1.push(d2[p2].c-d1[p1].c);
                vis[d1[p1].idx]=true;
                while(vis[d1[p1].idx])p1++;
                cnt1++;
            }
            else{
                cnt+=d2[p2].c;
                q2.push(d1[p1].c-d2[p2].c);
                vis[d2[p2].idx]=true;
                while(vis[d2[p2].idx])p2++;
                cnt2++;
            }
        }
        if(d1[p1].c<=0||d2[p2].c<=0){
            while(p1<=n&&d1[p1].c>0&&cnt1<=n/2){
                cnt+=d1[p1].c;
                vis[d1[p1].idx]=true;
                while(vis[d1[p1].idx])p1++;
                cnt1++;
            }
            while(p2<=n&&d2[p2].c>0&&cnt2<=n/2){
                cnt+=d2[p2].c;
                vis[d2[p2].idx]=true;
                while(vis[d2[p2].idx])p2++;
                cnt1++;
            }
            cout<<sum+cnt<<endl;
            continue;
        }
        if(cnt1>=n/2-1){
            while(d1[p1].c+q1.top()>0&&cnt2<=n/2){
                cnt+=d1[p1].c+q1.top();
                q1.pop();
                p1++;
                cnt2++;
            }
            while(d2[p2].c>0&&cnt2<=n/2){
                cnt+=d2[p2].c;
                vis[d2[p2].idx]=true;
                while(vis[d2[p2].idx])p2++;
                cnt2++;
            }
            cout<<sum+cnt<<endl;
            continue;
        }
        if(cnt2>=n/2-1){
            while(d2[p2].c+q2.top()>0&&cnt1<=n/2){
                cnt+=d2[p2].c+q2.top();
                q2.pop();
                p2++;
                cnt1++;
            }
            while(d1[p1].c>0&&p1<=n/2&&cnt1<=n/2){
                cnt+=d1[p1].c;
                vis[d1[p1].idx]=true;
                while(vis[d1[p1].idx])p1++;
                cnt1++;
            }
            cout<<sum+cnt<<endl;
            continue;
        }
    }
    return 0;
}
