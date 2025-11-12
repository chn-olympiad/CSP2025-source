#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005];
long long ans;
void f(int step,int val,int i,int k){
	if(step==i){
		if(val>2*a[k-1]){
			ans++;
		}
		return ;
	}
	if(k>n){
		return ;
	}
	f(step+1,val+a[k],i,k+1);
	f(step,val,i,k+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		f(0,0,i,1);
	}
	cout<<ans%998244353;
	return 0;
}