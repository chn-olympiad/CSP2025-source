#include<bits/stdc++.h>
using namespace std;
vector<int> v;
size_t n,m;
bool flag[501];
int c[501];
long long sum=0;
string s;
bool solve(){
	int j=0;
	for(size_t i=0;i<v.size();i++){
		if(v[i]<=j||s[i]=='0'){
			j++;
			continue;
		}
	}
	if(v.size()-j>=m) return true;
	return false;
}
void dfs(int nn){
	if(nn==0){
		if(solve()){
			sum++;
			sum%=998244353;
			return ;
		}
	}
	for(size_t i=1;i<=n;i++){
		if(flag[i]){
			flag[i]=0;
			v.push_back(c[i]);
			dfs(nn-1);
			flag[i]=1;
			v.erase(v.begin()+v.size()-1);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(size_t i=1;i<=n;i++){
		 cin>>c[i];
		 flag[i]=1;
	}
	bool flag=1;
	for(size_t i=0;i<s.size();i++) if(s[i]=='0'){
		flag=0;
		break;
	}
	if(flag){
		sum=1;
		for(size_t i=1;i<=n;i++){
			sum*=i;
		}
		cout<<sum%998244353;
		return 0;
	}
	dfs(n);
	cout<<sum;
	return 0;
}
/*
 1:1
 *2:2
 * 3: 123 132 213 231 312 321 6
 * 4:1234 1243 1324 1342 1423 1432 2134  
 * 
 * 1 2 6 24 120
 */
