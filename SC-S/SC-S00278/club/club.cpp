#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=-1e9;
int t,n,a[N],b[N],c[N],ans;
int cnt,cb,cc,dl[N],dp[205][105][105];
struct node{
	int num,id;
};
bool operator<(node x,node y){return x.num<y.num;}
priority_queue<node> qb,qc;
void del(){
	while(qb.size()&&dl[qb.top().id]) qb.pop();
	while(qc.size()&&dl[qc.top().id]) qc.pop();
}
bool check(){
	del();
	int res=inf;
	if(qb.size()) res=max(res,qb.top().num);
	if(qc.size()) res=max(res,qc.top().num);
	return res>0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=cb=cc=0;
		while(qb.size()) qb.pop();
		while(qc.size()) qc.pop();
		for(int i=1;i<=n;i++) dl[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=a[i];
		}
		if(n<=200){
			int res=0;
			dp[1][1][0]=a[1];
			dp[1][0][1]=b[1];
			dp[1][0][0]=c[1];
			for(int i=2;i<=n;i++){
				for(int j=0;j<=i;j++){
					for(int k=0;k<=i;k++){
						dp[i][j][k]=inf;
						if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]);
						if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+b[i]);
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+c[i]);
					}
				}
			}
			for(int i=1;i<=n/2;i++){
				for(int j=n/2-i;j<=min(n-i,n/2);j++){
					res=max(res,dp[n][i][j]);
				}
			}
			cout<<res<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			qb.push({b[i]-a[i],i});
			qc.push({c[i]-a[i],i});
		}
		for(int i=1;i<=n/2;i++){
			del();
			node x={inf,inf},y={inf,inf};
			if(qb.size()) x=qb.top();
			if(qc.size()) y=qc.top();
			if(x<y) qc.pop(),ans+=y.num,cc++,dl[y.id]=1;
			else{
				qb.pop(),ans+=x.num;dl[x.id]=1;
				if(b[x.id]-a[x.id]!=c[x.id]-a[x.id]) cb++;
			}
		}
		while(check()){
			if(cb==n/2){
				while(qb.size()){
					int j=qb.top().id;
					if(!dl[j]) qc.push({c[j]-a[j],j});
					qb.pop();
				}
			}
			if(cc==n/2){
				while(qc.size()){
					int j=qc.top().id;
					if(!dl[j]) qb.push({b[j]-a[j],j});
					qc.pop();
				}
			}
			node x={inf,inf},y={inf,inf};
			if(qb.size()) x=qb.top();
			if(qc.size()) y=qc.top();
			if(x<y) qc.pop(),ans+=y.num,cc++,dl[y.id]=1;
			else{
				qb.pop(),ans+=x.num;dl[x.id]=1;
				if(b[x.id]-a[x.id]!=c[x.id]-a[x.id]) cb++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}