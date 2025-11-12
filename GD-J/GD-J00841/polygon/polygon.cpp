#include<bits/stdc++.h>
using namespace std;
int a[10001];
int ans=0;int n;
void dp(int k,int sum,int s,bool w){
	if(k>n)
	return;	
	if(w)
	if(s>2){
		if(sum>a[k-1]*2){
			ans=(ans+1)%998244353;
		}		
	}
	dp(k+1,sum+a[k],s+1,1);
	dp(k+1,sum,s,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	dp(0,0,0,0);
	cout<<ans%998244353;
	return 0;
}
