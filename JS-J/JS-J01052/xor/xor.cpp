#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[50007],mx,n,k,ct=0;
pair<int,int> f[50007];
void dfs(int x,int sum){
	mx=max(mx,sum);
	if(x==ct+1) return;
	for(int i=x+1;i<=ct;++i){
		if(f[i].second<f[x].first||f[x].second<f[i].first){
		if(x==1) ++sum;
			dfs(i,sum+1);
		if(x==1) --sum;
		}
	}
	if(x==1) ++sum;
	mx=max(mx,sum);
	if(x==1) --sum;
	dfs(x+1,sum);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int fa=1,fb=1;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1) fa=0;
		if(a[i]>1) fb=0;
	}
	if(fa){
		cout<<n/2;
		return 0;
	}
	if(fb){
		if(k==1){
			for(int i=1;i<=n;++i){
				if(a[i]==1) ++ct;
			}
		}else{
			for(int i=1;i<=n;++i){
				if(a[i]==0) ++ct;
			}
			for(int i=1;i<=n;++i){
				if(a[i]==1&&a[i+1]==1) ++ct,++i;
			}
		}
		cout<<ct;
		return 0;
	}
	for(int i=2;i<=n;++i) a[i]^=a[i-1];
	for(int j=1;j<=n;++j)
		if(a[j]==k)  f[++ct].first=1,f[ct].second=j;
	for(int i=2;i<=n;++i){
		for(int j=i;j<=n;++j){
			if((a[j]^a[i-1])==k) f[++ct].first=i,f[ct].second=j;
		}
	}
	sort(f+1,f+ct+1);
	dfs(1,0);
	cout<<mx;
	return 0;
}
