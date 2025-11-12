#include <bits/stdc++.h>
using namespace std;
int a[5005],n,ans;
vector<int> v;
void dfs(int st,vector<int> s){
	if(st==n+1){
		int vmax=-1,sum=0,cnt=0; 
		for(int i=0;i<st-1;i++){
			if(s[i]==1){
				sum+=a[i+1];
				cnt++;
				vmax=max(vmax,a[i+1]);
			}
		}
		if(cnt>=3&&sum>2*vmax){
			ans++;
		}
		return ;
	}
	s.push_back(1);
	dfs(st+1,s);
	s.pop_back();
	s.push_back(0);
	dfs(st+1,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=27){
		dfs(1,v);
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
