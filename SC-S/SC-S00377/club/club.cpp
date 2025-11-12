#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int n,t,ans,m;
int a[MAXN][5];
vector<int> v;

void dfs(int now,int x1,int x2,int x3,int sum){
	if(now>n){
		ans=max(ans,sum);
		return ;
	}
	if(x1<m) dfs(now+1,x1+1,x2,x3,sum+a[now][1]);
	if(x2<m) dfs(now+1,x1,x2+1,x3,sum+a[now][2]);
	if(x3<m) dfs(now+1,x1,x2,x3+1,sum+a[now][3]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie();cout.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		v.clear(),ans=0;
		for(int i=1;i<=n;i++){
			v.push_back(a[i][1]);
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		else{
			sort(v.begin(),v.end());
			for(int i=0;i<m;i++) ans+=v[i];
			cout<<ans<<endl;
		}
	}
	
	return 0;
}