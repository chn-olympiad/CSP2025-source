#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n;
const int Mod=998244353;
long long ress;
void dfs(int djg,int s,int sum,int I){
	if(djg>I){
		return ;
	}
	if(sum>s){
		ress++;
		ress%=Mod;
	}
	for(int i=djg+1;i<=I;i++){
		dfs(i,s,sum+a[i],I);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=3;i<=n;i++){
		int j=i-1;
		ress=0;
		dfs(0,a[i],0,j);
		ans+=ress;
		ans%=Mod;
	}
	cout<<ans;
	return 0;
}
