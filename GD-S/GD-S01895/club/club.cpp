#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
const int N=1e5+5;
int a[N][3];
priority_queue<pii,vector<pii>,greater<pii> >d[3];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	int sum=0;
	for(int i=1;i<=n;i++){
		int mx=-1,p=0;
		for(int j=0;j<3;j++){
			if(d[j].size()==n/2){
				if(a[i][j]-d[j].top().fi>mx)
					mx=a[i][j]-d[j].top().fi,p=j;
			}else if(a[i][j]>mx)mx=a[i][j],p=j;
		}
		if(d[p].size()==n/2){
			int u=d[p].top().se;d[p].pop();
			mx=-1;int q=0;
			for(int j=0;j<3;j++)
				if((j^p)&&a[u][j]>mx)
					mx=a[u][j],q=j;
			sum+=a[u][q]-a[u][p],d[q].push(mp(a[u][q]-a[u][p],u));
		}
		mx=-1;int q=0;
		for(int k=0;k<3;k++)
			if((k^p)&&a[i][k]>mx)
				mx=a[i][k],q=k;
		sum+=a[i][p],d[p].push(mp(a[i][p]-a[i][q],i));
	}
	cout<<sum<<'\n';
	for(int i=0;i<3;i++)
		while(!d[i].empty())d[i].pop();
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;cin>>_;
	while(_--)solve();
	return 0; 
}
