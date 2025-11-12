#include<bits/stdc++.h>
using namespace std;
int n;
int l[5005];
long long ans;
int maxl;
bool cmp(int x1,int x2){
	return x1>x2; 
}
void solve(int idx,int sum){
	if(idx>n){
		if(sum>maxl){
			ans++;
			ans%=998244353;
		}
		return;
	}
	solve(idx+1,sum);
	solve(idx+1,sum+l[idx]);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1,cmp); 
	for(int i=1;i<=n;i++){
		maxl=l[i];
		solve(i+1,0);
	}
	cout<<ans;
	return 0;
} 
