#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[505],a[505],ans;
vector<vector<int>>v;
vector<int>ds;
bool f[20];
void dfs(int step){
	if(step==n+1){
		v.push_back(ds);
		return;
	}
	for(int i=1;i<=n;++i){
		if(f[i])continue;
		ds.push_back(i);
		f[i]=1;
		dfs(step+1);
		ds.pop_back();
		f[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=s.size();++i){
		a[i]=a[i-1];
		if(i>=2&&s[i-2]=='0')a[i]++;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
//		cout<<a[i]<<' ';
	}
//	for(int i=1;i<=n;++i)cout<<a[i];
	if(n<=10){
		dfs(1);
		for(auto ve:v){
//			for(auto i:ve)cout<<i<<' ';
//			cout<<endl;
			int cnt=0,day=1;
			for(auto i:ve){
				if(s[day-1]=='1'&&a[day]<c[i])cnt++;
				day++;
			}
//			cout<<cnt<<endl;
			if(cnt>=m)ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
//0 1 1
//0001111122
