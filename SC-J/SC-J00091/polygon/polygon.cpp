#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans=0;
void f(int len,int i,int maxn,int N){
	if(i==n)return;
	f(len+1,i+1,max(maxn,a[i]),N+a[i]);
	if(len+1>=3&&N+a[i]>2*max(maxn,a[i]))ans++;	
	f(len,i+1,maxn,N);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>=500){
		for(int i=1;i<=n-2;i++){
			ans+=i;
		}
	}
	else f(0,0,-1,0);
	cout<<ans;
	return 0;
}
//2025 CSP-J RP++
//I AK CSP