#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,ans,sum;
long long a[5005];
void sol(int s,int x,int y){
	if(x==y+1){
		if(sum>(2*a[s])){
			ans++;
			ans%=mod;
		}
		return;
	}
	if(x==1&&s==n-1){
		sum=0;
		sol(1,1,y+1);
	}
	if(y==n+1){
		return;
	}
	for(int i=s;i<=n;i++){
		sum+=a[i];
		sol(i+1,x+1,y);
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sol(1,1,3);
	cout<<ans;
	return 0;
}
