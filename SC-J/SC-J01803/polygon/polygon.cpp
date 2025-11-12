#include<bits/stdc++.h> 
using namespace std;
long long n,p[500005];
int dp(int mp[500005],int po){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp({mp,p[i]},po++);
	}
	if(po<3)return ans;
	else{
		int mx=0;
		for(int i=1;i<=po;i++) mx=max(mx,mp[i]);
		int gi=0;
		for(int i=1;i<=po;i++) gi=gi+mp[i];
		if(gi>2*mx) return ans++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	cout<<dp({},0);
}