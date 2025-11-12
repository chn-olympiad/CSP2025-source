#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int dp[500005][2];
int a[500005],dx;
int yh(int x,int y){
	int ans=a[x];
	for(int i=x+1;i<=y;i++){
		ans=ans|a[i];
	}
	return ans;
}
void b(int x){
	for(int i=x;i<=n;i++){
		if(yh(x,i)==k){
			cnt++;
		}
	}
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cnt++;
		if(a[0]==k){
			cnt++;
		}
		if(a[1]==k){
			cnt++;
		}
		if((a[1]|a[0])==k&&cnt==0){
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	b(1);
	cout<<cnt;
	return 0;
}
