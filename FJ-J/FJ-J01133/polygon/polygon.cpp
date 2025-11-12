#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],anss;
vector<long long> ans;
void dfs(long long start,long long length,long long now){
	if(length==now){
		long long temp=0,he=0;
		for(long long i=0;i<now;i++){
			temp=max(ans[i],temp);
			he+=ans[i]; 
		}
		if(he>temp*2){
			anss++;
		}
		return ;
	}
	for(long long j=start;j<=n;j++){
		ans.push_back(a[j]);
		dfs(j+1,length,ans.size());
		ans.pop_back();
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=3;i<=n;i++){
		dfs(1,i,0);
	}
	cout<<anss%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
/*
AK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOIAK IOI
*/ 
