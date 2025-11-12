#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int a[5005];
int C(int nn,int m){
	int u,d;
	u=d=1;
	for(int i=nn;i>=nn-m+1;i--){
		u*=i;
		u=u%998244353;
	}
	for(int j=1;j<=m;j++){
		d*=j;
		d=d%998244353;
	}
//	cout<<u<< ' '<<d<<endl;
	return u/d;
}
bool vis[5005];
int cnt=0;
void dfs(int st,vector<int>ans){
	if(ans.size()>=3){
		int mx=-1e9;
		int sum=0;
		for(int i:ans){
			mx=max(mx,a[i]);
			sum+=a[i];
		}
		if(sum>2*mx) {
			/*for(int i:ans){
				cout<<i<<' '; 
			} 
			cout<<endl;*/
			cnt++;
			cnt=cnt%998244353;
		}
	}
	for(int i=st+1;i<=n;i++){
		ans.push_back(i);
		dfs(i,ans);
		ans.pop_back();
	}
} 
signed main(){
		//cout<<C(5,4);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	int mx=-1e9;
	for(int i=1;i<=n;i++)
		mx=max(mx,a[i]);
	if(mx==1){
		int rs=0;
		for(int i=3;i<=n;i++){
			rs+=C(n,i);
			rs=rs%998244353;
		}
		cout<<rs;
	}
	else{
		vector<int>v;
		for(int i=1;i<=n;i++){
			v.push_back(i); 
			dfs(i,v);
			v.pop_back();
		}
		cout<<cnt;
	}
	
}
/*
哎，怎么又到csp了

这一整年有半年都在水

前2题还比较简单，预计200pts

第三题写了个妙妙代码，ai很大时跑的飞快，比较下时慢的像乌龟一样，应该65pts

第4题应该50pts

共100+100+65+50=315

应该一=

希望上迷惑

uid=1320771 

 

*/ 
