#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<long long>v[3];
bool f[N];
long long a[N],b[N],c[N];
long long n,ans,T;
void dfs(long long step){
	if(step==n+1){
		long long sum=0;
		for(auto it:v[0]){
			sum+=a[it];
		}for(auto it:v[1]){
			sum+=b[it];
		}for(auto it:v[2]){
			sum+=c[it];
		}ans=max(ans,sum);
	}for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(v[0].size()<n/2){
				v[0].push_back(i);
				dfs(step+1);
				v[0].erase(v[0].end()-1);
			}if(v[1].size()<n/2){
				v[1].push_back(i);
				dfs(step+1);
				v[1].erase(v[1].end()-1);
			}if(v[2].size()<n/2){
				v[2].push_back(i);
				dfs(step+1);
				v[2].erase(v[2].end()-1);
			}f[i]=0;
		}
	}
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		bool flg=0,flg2=0,flg3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]||c[i])flg=1;
			if(a[i]||c[i])flg2=1;
			if(a[i]||b[i])flg3=1;
		}if(!flg){
			sort(a+1,a+n+1,greater<long long>());
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}cout<<ans<<'\n';
			ans=0;
		}else if(!flg2){
			sort(b+1,b+n+1,greater<long long>());
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}cout<<ans<<'\n';
			ans=0;
		}else if(!flg3){
			sort(c+1,c+n+1,greater<long long>());
			for(int i=1;i<=n/2;i++){
				ans+=b[i];
			}cout<<ans<<'\n';
			ans=0;
		}else{
			dfs(1ll);
			cout<<ans<<'\n';
			ans=0;
		}
	}
	return 0;
}
