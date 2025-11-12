#include<bits/stdc++.h>
using namespace std;
int n,m;
int naixin[504];
string l;
unsigned long long int ans=0;
const unsigned long long int most=998244353;
void prin(vector<int> b){
	for(int i=0;i<b.size();i++) cout<<b[i];
	cout<<endl;
}
bool in(int a,vector<int> b){
	for(int i=0;i<b.size();i++){
		if(a==b[i]) return true;
	}
	return false;
}
int dfs(vector<int> r,int loser){
	if(loser>n-m) return 0;
	if(r.size()==n){
		if(loser<=n-m) {
			ans++;
		}
		return 0;
	}	
	for(int i=0;i<n;i++){
		if(in(i,r)) continue;
		vector<int> r_=r;
		r_.push_back(i);
		if(l[r.size()]=='0'||naixin[i]<=loser) dfs(r_,loser+1);
		else dfs(r_,loser);
		
	}
}
int main (){
	freopen("employ.in","r",stdin);
	freopen("emply.out","w",stdout);
	cin>>n>>m;
	cin>>l;
	for(int i=0;i<n;i++){
		cin>>naixin[i];
	}
	vector<int> r;
	dfs(r,0);
	cout<<ans%most;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
