#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int a[5005],n;
int ans=0;
void dfs(int ma,int sum,int cnt,int k){
	if(sum>2*ma&&cnt>=3){
		ans%=mod;
		ans++;
		return;
	}
	for(int i=k+1;i<n;i++){
		dfs(max(ma,a[i]),sum+a[i],cnt+1,i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int ma=INT_MIN;
	int sum=0;
for(int i=0;i<n;i++){
	cin>>a[i];
	ma=max(ma,a[i]);
	sum+=a[i];
}
if(n<3){
	cout<<0;
}else if(n==3){//12
	if(sum>2*ma){
		cout<<1;
	}else{
		cout<<0;
	}
}else if(n<=20){//40
	for(int i=0;i<n;i++){
		dfs(a[i],a[i],1,i);
	}
	cout<<ans;
}
	return 0;
}
