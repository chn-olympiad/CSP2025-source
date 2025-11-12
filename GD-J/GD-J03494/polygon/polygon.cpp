#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
vector<string> v;
map<string,int> mp;
void dfs(int s,int d,int an,int m,string method){
	if (d>=3 && an>m && !mp[method]){
		//cout<<method<<"\n";
		//v.push_back(method);
		//cout<<1<<" ";
		mp[method]=1;
		ans++;
		ans%=998244353;
	}
	//cout<<s<<" "<<d<<" "<<an<<" "<<m<<" "<<"\n";	
	if (s>n){
		return ;
	}
	dfs(s+1,d+1,an+a[s],a[s]*2,method+(char)(s-1+'1'));
	dfs(s+1,d,an,m,method);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0,"");
	//sort(v.begin(),v.end());
	/*
	for (int i=0;i<v.size();i++){
		while (v[i]==v[i+1]){
			ans--;
			i++;
		}
	}
	*/
	cout<<ans%998244353;
	return 0;
} 
