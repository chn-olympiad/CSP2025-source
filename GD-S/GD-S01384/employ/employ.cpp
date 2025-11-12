#include <bits/stdc++.h>
using namespace std;
constexpr int N=20;
int now[N];
bool vis[N];
int n,m;
int ans=0;
constexpr int M=505;
int c[M];
constexpr int mod=998244353;
void dfs(int step,int cnt,int done){//0<=step<n
	if(step>=n){
//		for(int i=0;i<n;++i) cout<<now[i]<<" ";
//		cout<<"\n";
		++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=1;
		now[step]=i;
		if(now[0]==2 and now[1]==1 and now[2]==3) cout<<"check1\n";
		if(step==n-1){
			for(int i=0;i<n;++i) cout<<now[i]<<" ";
			cout<<endl;
		}
		bool flag=1;
		if(cnt>=c[now[step]] and done) flag=0;
		if(flag) dfs(step+1,cnt+1,done);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;++i){
		cin>>c[i];
	}
	vector<int>p;
	for(int i=0;i<n;++i) p.push_back(i);
	do{
		bool flag=1;
		int leave=0;
		for(int i=0;i<n;++i){
			if(s[i]=='0') ++leave;
			else if(leave>=c[p[i]]) ++leave;
		}
		if(n-leave>=m) ++ans;
	}while(next_permutation(p.begin(),p.end()));
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
