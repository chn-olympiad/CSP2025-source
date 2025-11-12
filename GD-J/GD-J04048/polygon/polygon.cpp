#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans;
ll a[5010];
vector<int> v;
bool check(){
	int sum=0,mx=0;
	for(auto i:v){
		sum+=i;
		mx=max(mx,i);
	}
		//cout<<"---------------\n";
	return sum>2*mx;
}
void dfs(int x,int sum,int s){
	//cout<<"sum:"<<sum<<' '<<"s:"<<s<<'\n';
	if(sum==s){
		if(check()){
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	if(x>n){
		return;
	}
	dfs(x+1,sum,s);
	v.push_back(a[x]);
	dfs(x+1,sum+1,s);
	//for(auto i:v){
		//cout<<i<<' ';
	//}cout<<'\n';
	v.pop_back();
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,i);
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
