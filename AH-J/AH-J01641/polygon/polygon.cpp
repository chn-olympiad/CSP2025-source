#include<bits/stdc++.h>
using namespace std;
	long long n,ans=0;
	vector <long long>put;
bool cmp(long long x,long long y){
	return x>y;
}
void dfs(long long num,long long size,long long lazy){
	if(size<0){
		ans++;
	}
	for(int i=num+1;i<n;i++){
		dfs(i,size-put[i],lazy);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long in;
		cin>>in;
		put.push_back(in);
	}
	sort(put.begin(),put.end(),cmp);
	for(int i=0;i<put.end()-put.begin();i++){
		dfs(i,put[i],put[i]);
	}
	cout<<ans;
	return 0;
}
