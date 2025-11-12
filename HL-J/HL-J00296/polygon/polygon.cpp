#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int baohan[5001];
int a[5001];
int ans=0;
bool dfs(int sum,int ma,int insrt,int dress){
	if(insrt<ma){
		baohan[insrt]--;
		if(baohan[insrt]<0){
			baohan[insrt]++;
			return false;
		}
		ans++;
		dfs(sum+insrt,insrt,a[dress+1],dress+1);
		baohan[insrt]++;
		return true;
	}
	if(sum>insrt){
		baohan[insrt]--;
		if(baohan[insrt]<0){
			baohan[insrt];
			return false;
		}
		ans++;
		dfs(sum+insrt,insrt,a[dress+1],dress+1);
		baohan[insrt]++;
		return true;
	}
	return false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		baohan[a[i]]++;
	}
	for(int i=0;i<n;i++){
		baohan[a[i]]--;
		for(int j=i+1;j<n;j++){
			baohan[a[j]]--;
			int sum=a[i]+a[j];
			int ma=max(a[i],a[j]);
			for(int x=j+1;x<n;x++){
				dfs(sum,ma,a[x],x);
			}
			baohan[a[j]]++;
		}
		baohan[a[i]]++;
	}
	cout<<ans;
	return 0;
}
