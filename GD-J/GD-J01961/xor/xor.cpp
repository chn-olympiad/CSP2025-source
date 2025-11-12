#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x[500005],maxn,sum1;
bool vis[500005];
int calc1(){
	int sum=0;
	for(int i=1;i<n;i++){
		if(a[i]==1&&a[i+1]==1){
			sum++;
			i=i+2;
		}
	}
	return sum;
}
int calc2(){
	int sum=0;
	for(int i=1;i<n;i++){
		if((a[i]==0&&a[i+1]==1)||(a[i]==1&&a[i+1]==0)){
			sum++;
			i=i+2;
		}
	}
	return sum;
}
void dfs(int j){
	if(j==n){
		int sum=0,y=0;
		for(int i=1;i<=n;i++){
			if(x[i-1]||i==1){
				y=a[i];
			}else{
				y^=a[i];
			}
			if(x[i]){
				if(y==k){
					sum++;
				}
			}
		}
		if(y==k){
			sum++;
		}
		maxn=max(maxn,sum);
		return;
	}
	x[j]=1;
	dfs(j+1);
	x[j]=0;
	dfs(j+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum1+=(a[i]==1);
	}
	if(sum1==n&&k==0){
		cout<<n/2;
	}else if(k==0){
		cout<<n-sum1+calc1();
	}else if(k==1){
		cout<<max(sum1,calc2());
	}else{
		dfs(1);
		cout<<maxn;
	}
	return 0;
}
