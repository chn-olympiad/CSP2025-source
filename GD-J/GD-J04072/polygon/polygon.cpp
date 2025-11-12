#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[5005],sumn=0;
bool bj[5005];

void dfs(int s,int k,int maxn){
	if(k>=3){
		if(s>maxn*2){
			sumn++;
			return ;
		}
		if(k==n){
			return ;
		}
	}
	for(int i=1;i<=n;i++){
		if(bj[i]==0){
			s+=a[i];
			k++;
			bj[i]=1;
			int hc=maxn;
			maxn=max(maxn,a[i]);
			dfs(s,k,maxn);
			s-=a[i];
			k--;
			bj[i]=0;
			maxn=hc;
		}
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<sumn%998244353;
	
	
	return 0;
}

