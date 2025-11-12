#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int N,cnt;
int a[5005];
void find(int n,int k,int p,int ans,int max1){
	if(n==k){
		if(ans>2*max1){
			cnt++;
			cnt%=mod;
		}
		return;
	}else{
		for(int i=1;p+i<=N;i++){
			find(n,k+1,p+i,ans+a[p+i],max(max1,a[p+i]));
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	sort(a+1,a+N+1);
	for(int i=3;i<=N;i++){
		find(i,0,0,0,0);
	}
	cout<<cnt;
	return 0;
}
