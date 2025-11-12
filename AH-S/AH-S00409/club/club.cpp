/*
*/
#include<bits/stdc++.h>
#define in(a) scanf("%d",&a)
#define N 100005
#define ll long long
using namespace std;
struct club{
	ll w;
	int cnt[4];
}dp[N][4];//dp[i][j]表示第i个人进入第j个社团的最大值
int t;
int sum=0;
int n;
struct point{
	int p[4];
}a[N];
struct num{
	int w,id;
};
struct club1{
    num v[4];
}a1[N];
int cnt1[5];
bool cmp(club1 x,club1 y){
	return x.v[1].w>y.v[1].w;
}
bool cmp1(num x,num y){
    return x.w>y.w;
}
int g[15][3];
int w[N];
int cnt12[5];
void dfs(int x){
    if(x==n+1){
        int ans_s=0;
        for(int i=1;i<=n;i++){
            ans_s+=g[i][w[i]];
        }
        sum=max(sum,ans_s);
        return ;
    }
    for(int i=1;i<=3;i++){
        if(cnt12[i]>=n/2) continue;
        cnt12[i]++;
        w[x]=i;
        dfs(x+1);
        cnt12[i]--;
    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=4){
            for(int i=1;i<=n;i++) cin>>g[i][1]>>g[i][2]>>g[i][3];
            sum=0;
            dfs(1);
            cout<<sum<<"\n";
            continue;
        }
        ll ans=0;
        memset(cnt1,0,sizeof(cnt1));
        for(int i=1;i<=n;i++){
            in(a[i].p[1]),in(a[i].p[2]),in(a[i].p[3]);
            a1[i].v[1].w=a[i].p[1],a1[i].v[2].w=a[i].p[2],a1[i].v[3].w=a[i].p[3];
            a1[i].v[1].id=1,a1[i].v[2].id=2,a1[i].v[3].id=3;
            sort(a1[i].v+1,a1[i].v+3+1,cmp1);
        }
        sort(a1+1,a1+n+1,cmp);
        for(int i=1;i<=n;i++){
			club1 u=a1[i];
			if(u.v[1].w>u.v[2].w){
                if(cnt1[u.v[1].id]<n/2){//最大值还能加入
                    cnt1[u.v[1].id]++;
                    ans+=u.v[1].w;
                }else{
                    if(u.v[2].w>u.v[3].w){
                        if(cnt1[u.v[2].id]<n/2){//第二大还能加入
                            cnt1[u.v[2].id]++;
                            ans+=u.v[2].w;
                        }else{
                            cnt1[u.v[3].id]++;
                            ans+=u.v[3].w;
                        }
                    }else{//有2个第二大的值
						ans+=u.v[3].w;
                        cnt1[3]++;
                    }
                }
			}else{
                if(u.v[2].w>u.v[3].w){//有2个最大值
                    if(cnt1[2]<n/2) cnt1[2]++;
                    else cnt1[1]++;
                    ans+=u.v[2].w;
                }else{//三个值都相等
					ans+=u.v[1].w;
                    if(cnt1[3]<n/2) cnt1[3]++;
                    else cnt1[2]++;
				}
			}
        }
        for(int i=1;i<=n;i++){
            dp[i][1].w=dp[i][2].w=dp[i][3].w=0;
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    //现在考虑dp[i][k]能否继承dp[i-1][j]
                    if(dp[i-1][j].cnt[k]<n/2){
						if(dp[i-1][j].w+a[i].p[k]>=dp[i][k].w){
							dp[i][k]=dp[i-1][j];
							dp[i][k].w+=a[i].p[k];
							dp[i][k].cnt[k]++;
						}
					}
                }
            }
		}
		cout<<max(ans,max(dp[n][1].w,max(dp[n][2].w,dp[n][3].w)))<<"\n";
    }
    return 0;
}
