#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

const int N=505,mod=998244353;

int n,m;
int s[N],c[N];

bool vis[N];
int a[N];
int ans;

void dfs(int x){
	if(x==n+1){
		int pre=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(pre>=c[a[i]]||s[i]==0)
				pre++;
			else
				cnt++;
		}
		ans+=(cnt>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		a[x]=i;
		dfs(x+1);
		vis[i]=false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}

