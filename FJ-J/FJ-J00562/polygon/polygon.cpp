#include <bits/stdc++.h>
using namespace std;
int a[5010];
long long sum=0;
void js(long long ans,int d,int i){
	if(ans+a[i]>d){
		sum++;
		sum%=998244353;
	}
	for(int j=i-1;j>=1;j--) js(ans+a[i],d,j);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--){
		for(int j=i-1;j>=2;j--){
			for(int k=j-1;k>=1;k--) js(a[j],a[i],k);
		}
	}
	cout<<sum%998244353;
	return 0;
}
