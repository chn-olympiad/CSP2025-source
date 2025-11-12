#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
bool isp(vector<int> v,int s,int g){
	int ans=0,maxn=-1;
	while(s<=g){
		ans+=v[s];
		maxn=max(v[s],maxn);
		s++;
	}
	if(ans>maxn)return true;
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	long long ans=0;
	cin>>n;
	vector<int>a;
	for(int i=0;i<n;i++){
		a.push_back(0);
		cin>>a[i];
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<n-3;i++){
		for(int j=3;j<=n;j++){
			if(isp(a,i,j))ans++;
		}
	}
	cout<<ans;
	return 0;
}  
