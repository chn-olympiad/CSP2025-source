#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],b[100005],c[100005];
ll m[5];
ll t,n,ans=-1;
priority_queue<ll>q;
void dfs(ll cnt,ll p){
	if(p==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(m[1]<n/2&&m[2]<n/2&&m[3]<n/2){
		m[1]++;
		dfs(cnt+a[p],p+1);
		m[1]--;
		m[2]++;
		dfs(cnt+b[p],p+1);
		m[2]--;
		m[3]++;
		dfs(cnt+c[p],p+1);
		m[3]--;
	}
	else if(m[1]>=n/2&&m[2]<n/2&&m[3]<n/2){
		m[2]++;
		dfs(cnt+b[p],p+1);
		m[2]--;
		m[3]++;
		dfs(cnt+c[p],p+1);
		m[3]--;
	}
	else if(m[1]>=n/2&&m[2]>=n/2&&m[3]<n/2){
		m[3]++;
		dfs(cnt+c[p],p+1);
		m[3]--;
	}
	else if(m[1]<n/2&&m[2]>=n/2&&m[3]<n/2){
		m[1]++;
		dfs(cnt+a[p],p+1);
		m[1]--;
		m[3]++;
		dfs(cnt+c[p],p+1);
		m[3]--;
	}
	else if(m[1]<n/2&&m[2]<n/2&&m[3]>=n/2){
		m[1]++;
		dfs(cnt+a[p],p+1);
		m[1]--;
		m[2]++;
		dfs(cnt+b[p],p+1);
		m[2]--;
	}
	else if(m[1]>=n/2&&m[2]<n/2&&m[3]>=n/2){
		m[2]++;
		dfs(cnt+b[p],p+1);
		m[2]--;
	}
	else{
		m[1]++;
		dfs(cnt+a[p],p+1);
		m[1]--;
	}
}
void dfs2(ll cnt,ll p){
	if(p==n+1){
		ans=max(ans,cnt);
		return;
	}
	if(m[1]<n/2&&m[2]<n/2){
		m[1]++;
		dfs(cnt+a[p],p+1);
		m[1]--;
		m[2]++;
		dfs(cnt+b[p],p+1);
		m[2]--;
	}
	else if(m[1]>=n/2&&m[2]<n/2){
		m[2]++;
		dfs(cnt+b[p],p+1);
		m[2]--;
	}
	else{
		m[1]++;
		dfs(cnt+a[p],p+1);
		m[1]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		while(!q.empty()) q.pop();
		bool f1=1,f2=1;
		ans=-1;
		cin>>n;
		m[1]=0;
		m[2]=0;
		m[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			q.push(a[i]);
			if(b[i]!=0) f1=0;
			if(c[i]!=0) f2=0;
		}
		if(f1==0&&f2==0)
			dfs(0,1);
		else if(f1==1&&f2==1){
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
			ans++;
		}
		else if(f1==0&&f2==1){
			dfs2(0,1);
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}
