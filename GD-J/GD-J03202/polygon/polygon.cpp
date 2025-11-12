#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int ans=0;
const int M=998244353;
void f(int n,int sum,int maxn){
	if(n==0){
		if(sum>maxn*2){
			ans++;
			ans%=M;
		}
		return;
	}
	f(n-1,sum,maxn);
	f(n-1,sum+a[n],max(maxn,a[n]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f(n,0,0);
	cout<<ans;
	return 0;
}
