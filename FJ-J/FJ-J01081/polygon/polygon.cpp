#include<bits/stdc++.h>
using namespace std;
int n,xxam=1,s=0,sss=0;
int a[5005]={0};
bool dfs(int z,int ss){
	if(z==n+1){
		if(ss<3){
			return 0;
		}
		if(s>xxam*2){
			sss++;
		}
		return 0;
	}
	s=s+a[z];
	int xx=xxam;
	xxam=max(a[z],xxam);
	dfs(z+1,ss+1);
	s=s-a[z];
	xxam=xx;
	dfs(z+1,ss);
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s=s+a[i];
		xxam=max(xxam,a[i]);
	}
	sort(a,a+n);
	if(n==3){
		if(s>xxam*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(xxam==1){
		cout<<n-2;
		return 0;
	}
	s=0;
	xxam=0;
	dfs(1,0);
	cout<<sss;
	return 0;
} 
