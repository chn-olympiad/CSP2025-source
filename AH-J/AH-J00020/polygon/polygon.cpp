#include<bits/stdc++.h>
using namespace std;

int n;

int arr[1111660];

bool espacial=true;

long long cnt=0;

void dfs(int ndx,int sum,int maxn,int has){
	if(ndx==n){
		if(sum>maxn*2){
			cnt++;
		}
		cnt=cnt%998244353;
		return;
	}
	if(n-ndx>3-has){
		dfs(ndx+1,sum,maxn,has);
	}
	dfs(ndx+1,sum+arr[ndx],max(maxn,arr[ndx]),has+1);
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=1){
			espacial=false;
		}
	}
	if(espacial){
		for(int i=3;i<=n;i++){
			long long now=1;
			for(int j=n;j>n-i;j--){
				now=(now*(j%998244353))%998255353;
			}
			for(int j=i;j>=1;j--){
				now=(now/(j%998244353))%998255353;
			}
			cnt=(cnt+(now%998244353))%998244353;
		}
		cout<<cnt;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<cnt;
	return 0;
}
