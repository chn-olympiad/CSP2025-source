//T4(40-44points)
#include<bits/stdc++.h>
using namespace std;
int a[100];
long long cnt;
int n;
vector<int>vec;
void dfs(int x){
	if(vec.size()>=3){
		int sum=0,mx=0;
		for(int i=0;i<vec.size();i++){
			sum+=a[vec[i]];
			mx=max(mx,a[vec[i]]);
		}
		if(sum>2*mx){
			cnt++;
		}
	}
	for(int i=x;i<=n;i++){
		vec.push_back(i);
		dfs(i+1);
		vec.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<cnt;
	return 0;
}
