#include<bits/stdc++.h>
using namespace std;
int tt, n;
struct not_QxE{
    long long x, y, z;
    bool used;
};
struct zjffff{
    long long qx,yl,dl,tc;
}dp[50005];
bool cmp1(not_QxE qx, not_QxE yl){
    if(qx.x!=yl.x)return qx.x > yl.x;
    else if(qx.y!=yl.y)return qx.y > yl.y;
    else return qx.z > yl.z;
}
not_QxE a[50005];
pair<long long, long long> book[35][35][35];
long long dfs(long long t, int cnt1,int cnt2,int cnt3, long long sum)
{
    long long sum1 = sum;
    if(t > n)return sum;
    if(cnt1>n/2||cnt2>n/2||cnt3>n/2)return sum;
    if(cnt1<n/2)sum1 = max(sum1,dfs(t+1,cnt1+1,cnt2,cnt3,sum+a[t].x));
    if(cnt2<n/2)sum1 = max(sum1,dfs(t+1,cnt1,cnt2+1,cnt3,sum+a[t].y));
    if(cnt3<n/2)sum1 = max(sum1,dfs(t+1,cnt1,cnt2,cnt3+1,sum+a[t].z));
    //printf("%d %d %d %d %d\n", t,cnt1,cnt2,cnt3,sum1);
    return sum1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>tt;
    while(tt--){
        memset(a,0,sizeof(a));
        cin >> n;
        int flag = 1;
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
            if(a[i].y+a[i].z>0)flag = 0;
        }
        if(flag){
	        sort(a+1,a+n+1,cmp1);
	        long long ans = 0;
	        for(int i = 1; i <= n/2;i++)ans+=a[i].x;
	        cout << ans << endl;
	    }
		long long ans = dfs(0,0,0,0,0) ;
        //ans += max(a[n].x,max(a[n].y,a[n].z));
        cout <<ans << endl;
        continue;
    }
    return 0;
}
