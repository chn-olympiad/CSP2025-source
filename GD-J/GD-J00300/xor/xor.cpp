#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
long long a[500005],k,maxa;
vector<long long> v[500005];
void dfs(int id,long long cnt){
	if(v[id].size()==0){
		maxa=max(maxa,cnt);
		return;
	}
	for(int i=0;i<v[id].size();i++){
		dfs(v[id][i]+1,cnt+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			x=(x^a[j]);
			if(x==k){
				v[i].push_back(j);
			}
		}
	}
	dfs(1,0);
	cout<<maxa;
	return 0;
}
