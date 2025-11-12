#include<bits/stdc++.h>
using namespace std;
int n,s[5124];//2
long long ans=0;
bool cmp(int a,int b){
	return a<=b;
}
void dfs(int k,int x,int sum,int maxx){
	if((x+k)<4||(x==0)) return;//kxg1
	else if(sum<=maxx)  {
		for(int i=1;i<x;i++){
			dfs(k+1,i,sum+s[i],maxx);//kxg2
		}
		if(k==1&&x+1<=n){
			dfs(k,x+1,0,s[x+1]);
		}
	}
	else{
		ans+=(1ll<<(x-1))%998244353;
		ans%=998244353;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1,cmp);
	dfs(1,3,0,s[3]);
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}//20 75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1//8,
