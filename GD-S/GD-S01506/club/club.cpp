#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int x,y,z,maxl;
}a[100005];
bool cmp(pair<int,int> x,pair<int,int> y) {
    if (x.first!=y.first) return x.first>y.first;
    return x.second<y.second;
}
int T,t1[100005];
pair<int,int> s1[100005],s2[100005],s3[100005];
bool vis[100005];
int ans;
void dfs(int p,int sum,bool flag1,bool flag2) {
	if (p==4) {
		ans=max(ans,sum);
		return;
	}
	if (p==1) {
		if (!flag1) dfs(p+1,sum+a[1].x,true,flag2);
		if (!flag2) dfs(p+1,sum+a[2].x,flag1,true);
		dfs(p+1,sum,flag1,flag2);
		ans=max(ans,sum);
	} 
	if (p==2) {
		if (!flag1) dfs(p+1,sum+a[1].y,true,flag2);
		if (!flag2) dfs(p+1,sum+a[2].y,flag1,true);
		dfs(p+1,sum,flag1,flag2);
		ans=max(ans,sum);
	} 
	if (p==3) {
		if (!flag1) dfs(p+1,sum+a[1].z,true,flag2);
		if (!flag2) dfs(p+1,sum+a[2].z,flag1,true);
		dfs(p+1,sum,flag1,flag2);
		ans=max(ans,sum);
	}
}
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
    while (T--) {
        int n,tot1=0,tot2=0,tot3=0;
        bool flag1=true;
        ans=0;
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i].x>>a[i].y>>a[i].z,a[i].maxl=max({a[i].x,a[i].y,a[i].z}),vis[i]=false;
            t1[i]=a[i].x;
            if (a[i].maxl==a[i].x) s1[++tot1]={a[i].maxl,i};
            if (a[i].maxl==a[i].y) s2[++tot2]={a[i].maxl,i};
            if (a[i].maxl==a[i].z) s3[++tot3]={a[i].maxl,i};
            if (a[i].y!=0 || a[i].z!=0) flag1=false;
        }
        if (n==2) {
        	dfs(1,0,false,false);
        	cout<<ans<<'\n';
        	continue;
		}
        if (flag1) {
            sort(t1+1,t1+1+n,greater<int>());
            for (int i=1;i<=n/2;i++)
                ans+=t1[i];
            cout<<ans<<'\n';
            continue;
        }
        sort(s1+1,s1+1+tot1,cmp);
        sort(s2+1,s2+1+tot2,cmp);
        sort(s3+1,s3+1+tot3,cmp);
        int cnt=0;
        for (int i=1;i<=tot1;i++) {
        	if (cnt>=n/2) break;
            if (cnt<n/2) cnt++,ans+=s1[i].first,vis[s1[i].second]=true;
        }
        cnt=0;
        for (int i=1;i<=tot2;i++) {
			if (cnt>=n/2) break;
            if (cnt<n/2 && !vis[s2[i].second]) cnt++,ans+=s2[i].first,vis[s2[i].second]=true;
        }
        cnt=0;
        for (int i=1;i<=tot3;i++) {
        	if (cnt>=n/2) break;
            if (cnt<n/2 && !vis[s3[i].second]) cnt++,ans+=s3[i].first,vis[s3[i].second]=true;
        }
        cout<<ans<<'\n';
    }
	return 0;
}

