#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>> q;
int a[500005];
int b[500005];
int flag[1050000];
int flag2[1050000];
int e(int x,int y) {
	int ans=0,cnt=0;
	while(x!=0 || y!=0) {
		if(x%2==y%2) {
			ans=ans;
			cnt++;
		}
		if(x%2!=y%2) {
			ans=ans+pow(2,cnt);
			cnt++;
		}
		x/=2;
		y/=2;
	}
	return ans;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=e(b[i-1],a[i]);
	}
	for(int i=n;i>=0;i--){
		if(flag2[e(k,b[i])]!=0){
			q.push({-flag[e(k,b[i])],i+1});
		}
		flag2[b[i]]=1;
		flag[b[i]]=i;
	}
	int ans=0;
	int s=0;
	while(!q.empty()){
		if(q.top().second>s){
			s=-q.top().first;
			ans++;
		}
		q.pop();
	}
	cout<<ans;
	return 0;
}