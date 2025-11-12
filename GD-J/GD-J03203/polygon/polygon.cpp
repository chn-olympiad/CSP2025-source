#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int line[5010]={};
int n;
long long dfs(int step,int sum,int maxx,int back){
	if(step>n){
		if(sum>maxx*2)return 1;
		return 0;
	}
	if(back+sum<=maxx*2)return 0;
	int a=dfs(step+1,sum,maxx,back-line[step]);
	int b=dfs(step+1,sum+line[step],max(maxx,line[step]),back-line[step]);
	return((a+b)%MOD);
}
long long modf(int a,int x){
	long long ans=1;
	for(int i=1;i<=x;i++){
		ans=ans*a%MOD;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>line[i];
		sum+=line[i];
		if(line[i]!=1){
			flag=false;
		}
	} 
	if(flag){
		cout<<(modf(2,n)-n-n*(n-1)/2)%MOD;
		return 0;
	}
	cout<<dfs(1,0,0,sum);
	return 0;
}
