#include<bits/stdc++.h>
using namespace std;
const int CC=998244353;
int n,s[5002],p[5002],maxn=-1e7,ans;
bool s1[5002];
void dfs(int k,int j,int min){
	if (k==j+1){
		int sum=0;
		for(int i=1;i<=j;i++){
			sum+=p[i];
		}
		if (sum>2*p[j]){
			ans++;
		}
		return;
	}
	for (int i=min+1;i<=n;i++){
		if (!s1[i]){
			p[k]=s[i];
			s1[i]=true;
			dfs(k+1,j,i);
			p[k]=0;
			s1[i]=false;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin >>n;
	for (int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	for (int i=3;i<=n;i++){
		dfs(1,i,0);
	}
	while (ans>=CC){
		ans-=CC;
	}
	cout <<ans;
	return 0;
}