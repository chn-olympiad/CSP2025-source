#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+10;
LL ans,t,n,a[N][10],d[N][10];
void dfs(LL cur,LL cnt1,LL cnt2,LL cnt3,LL sum){
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
	if(cur>n){
		ans=max(ans,sum);
		return;
	}
	dfs(cur+1,cnt1+1,cnt2,cnt3,sum+a[cur][1]);
	dfs(cur+1,cnt1,cnt2+1,cnt3,sum+a[cur][2]);
	dfs(cur+1,cnt1,cnt2,cnt3+1,sum+a[cur][3]);
}
void Trysy(){
	dfs(1,0,0,0,0);
	cout<<ans;
}
void tryA(){
    priority_queue<LL> pq;
    for(LL i=1;i<=n;i++) pq.push(a[i][1]);
    LL sum=0;
    for(LL i=1;i<=n/2;i++){
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        LL isa=0,isb=0;
        ans=-0x3f3f3f3f3f3f3f3f;
        memset(d,0,sizeof d);
        cin>>n;
        for(LL i=1;i<=n;i++) for(LL j=1;j<=3;j++) cin>>a[i][j];
        for(LL i=1;i<=n;i++){
            if(a[i][2]==0&&a[i][3]==0) isa++;
            else if(a[3]==0) isb++;
        }
        if(isa==n) tryA();
        else Trysy();
        cout<<endl;
    }
    return 0;
}
