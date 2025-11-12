#include <bits/stdc++.h>
using namespace std;
int a[5005];
int qian[5005];
int modnum=998244353;
int mi(int zhi){
	int ans=1;
	for(int i=0;i<zhi;i++){
		ans*=2;
		ans%=modnum;
	}
	return ans;
}
int dfs(int last,int sum,int maxl){
	int ans=0;
	if(last==0){
		return 0;
	}
	if(qian[last-1]+sum<=maxl){
		return 0;
	}
	for(int i=last-1;i>=0;i--){
		if(qian[last-1]+sum<=maxl){
			break;
		}
		if(sum+a[i]>maxl){
			ans+=mi(i);
			ans%=modnum;
		}else{
			ans+=dfs(i,sum+a[i],maxl);
			ans%=modnum;
		}
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=0;
	qian[0]=a[0];
	for(int i=1;i<n;i++){
		qian[i]=qian[i-1]+a[i];
		//cout<<dfs(i,0,a[i])<<endl;
		ans+=dfs(i,0,a[i]);
		ans%=modnum;
	}
	cout<<ans;
	return 0;
}