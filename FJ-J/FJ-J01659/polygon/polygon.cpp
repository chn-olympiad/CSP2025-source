#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,l[5001],ans=0;
int pw(int a){
	int c=1;
	for(int i=0;i<a;i++){
		c*=2;
		c=c%998244353;
	}
	return c;
}
void dfs(int a,int s1,int s2){
	if(a==n){
		if(s2*2<s1){
			ans++;
		}
		return;
	}
	dfs(a+1,s1,s2);
	dfs(a+1,s1+l[a],max(s2,l[a]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool flag=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]!=1){
			flag=0;
		}
	}
	if(flag){
		cout<<(pw(n)-1-n-n*(n-1)/2)%998244353;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
