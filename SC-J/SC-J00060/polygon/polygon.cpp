#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a;
ll x;
vector<int> v;
int dfs(int p,int z){
	int b=0;
	for(int i=p+1;i<n;i++){
		if(z>v[i]) b++;
		b+=dfs(i,v[i]+z);
	}
	return b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			x+=dfs(j,v[i]+v[j]);
		}
	}
	cout<<x;
	return 0;
}