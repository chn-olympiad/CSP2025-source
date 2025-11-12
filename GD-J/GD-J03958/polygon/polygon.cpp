#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int mod=998244353;

int n,a[5001];
long long ans;
bool cmp(int x,int y){
	return x>y;
}

void dfs(int d,long long maxn,long long l,int s){

	if(d>2&&l>2*maxn){
		ans++;
		ans%=mod;
	}

		for(int i=s+1;i<=n;i++){
			if(d==0){
				dfs(1,a[i],a[i],i);
			}else{
				dfs(d+1,maxn,l+a[i],i);
			}
		}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
