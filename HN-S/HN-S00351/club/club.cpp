#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
using ll=long long;
using pii=pair<int,int>;
const int MN=1e5+10;
int n;
vector<vector<int>> a;
ll f[MN][4];
int ans=0;
void dfs(int x,int c,int sum,int c1,int c2,int c3){
	if(x==n){
		ans=max(sum,ans);
		return ;
	}
	if(c1<n/2) dfs(x+1,1,sum+a[x+1][1],c1+1,c2,c3);
	if(c2<n/2) dfs(x+1,1,sum+a[x+1][2],c1,c2+1,c3);
	if(c3<n/2) dfs(x+1,2,sum+a[x+1][3],c1,c2,c3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bool x23=1,x3=1;
		a.push_back({});
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a.push_back({});
			a[i].push_back(-1);
			a[i].push_back(x),a[i].push_back(y),a[i].push_back(z);
			if(y!=0||z!=0) x23=0;
			if(z!=0) x3=0;
		}
//		if(x3){
//			sort(a.begin(),a.end(),[](vector<int> a,vector<int> b){
//				if(a[1]!=b[1]) return a[1]>b[1];
//				if(a[2]!=b[2]) return a[2]>b[2];
//				return a[3]>b[3];
//			});
//			
//		}
		dfs(0,0,0,0,0,0);
//		f[1][1]=a[1][1];
//		f[1][2]=a[1][2];
//		f[1][3]=a[1][3];
//		for(int i=2;i<=n;i++){
//			priority_queue<pii,vector<pii>> q;
//			for(int j=1;j<=3;j++){
//				q.push({a[i-1][j],j});
//				//cout<<a[i-1][j]<<'\n';
//			}
//			for(int j=1;j<=3;j++){
//				f[i][j]=q.top().fir;
//				if(c[j]<n/2){
//					c[j]++;
//					f[i][j]+=a[i][j];
//				}else{
//					q.pop();
//				}
//				cout<<f[i][j]<<' ';
//			}//cout<<'\n';
//		}
//		ll ans=0;
//		for(int i=1;i<=3;i++){
//			ans=max(ans,f[n][i]);
//		}
		cout<<ans<<'\n';
	}
	return 0;
}
