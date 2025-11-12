#include<bits/stdc++.h>
using namespace std;

int a[5005];
int n;
//15
void solve1(){
	if(n<3){
		cout<<0;
	}
	int sum = a[1]+a[2]+a[3];
	int maxn = max(a[1],max(a[2],a[3]));
	if(sum>maxn*2){
		cout<<1;
	} 
	else{
		cout<<0;
	}
}
int cnt = 0;
int p = 0;
int k[5005];
void solve2(int sum,int maxn,int now,int total){
	if(now>=n){
		if(total<3){
			return;
		}
		if(sum>(2*maxn)){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=now+1;i<=n+1;i++){
		k[p+1] = a[i];
		p++;
		solve2(sum+a[i],max(maxn,a[i]),i,total+1);
		p--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool solve3x = 0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)
			solve3x = 1;
	}
	if(n<=3){
		solve1();
		return 0;
	}
	else if(solve3x==0){
		long long x = 1;
		for(int i=1;i<=n;i++){
			x*=2;
			x%=998244353;
		}
		x-=n*(n-1)/2;
		x%=998244353;
		x-=n;
		x%=998244353;
		x-=1;
		x%=998244353;
		cout<<x;
		return 0;
	}
	else{
		solve2(0,-1,0,0);
		cout<<cnt;
		return 0;
	}
	return 0;	
}