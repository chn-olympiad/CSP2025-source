#include<iostream>
using namespace std;
long long a=0,b[5005];
long long dfs(long long dang,long long z,long long zong,long long maxn){
	if(z>=3&&zong>maxn*2&&dang==a+1) return 1;
	if(dang==a+1) return 0;
	long long ans=0;
	ans+=dfs(dang+1,z,zong,maxn);
	if(b[dang]>=maxn){
		maxn=b[dang];
	}
	ans+=dfs(dang+1,z+1,zong+b[dang],maxn);
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++) cin>>b[i];
	cout<<dfs(1,0,0,-1);
	return 0;
}
