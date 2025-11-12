#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4];
int ans;
int p[4];
int cs[100005];
void dfs(int k,int sum){
	if(k>n){
//		for(int i=1;i<=n;i++)cout<<cs[i]<<" ";
//		cout<<sum<<endl;
		ans=max(ans,sum);
		return;
	}
	if(p[1]<n/2){
		p[1]++;
		cs[k]=1;
		dfs(k+1,sum+a[k][1]);
		p[1]--;
	}
	if(p[2]<n/2){
		p[2]++;
		cs[k]=2;
		dfs(k+1,sum+a[k][2]);
		p[2]--;
	}
	if(p[3]<n/2){
		p[3]++;
		cs[k]=3;
		dfs(k+1,sum+a[k][3]);
		p[3]--;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int wow(){
	vector<int> v;
	for(int i=1;i<=n;i++)v.push_back(a[i][1]);
	sort(v.begin(),v.end(),cmp);
	int ans=0;
	for(int i=0;i<n/2;i++){
		ans+=v[i];
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		memset(p,0,sizeof(p));
		cin>>n;
		bool ta=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(!(a[i][2]==0&&a[i][3]==0)){
				ta=0;
			}
		}
		if(ta){
			cout<<wow();
			return 0;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
}
