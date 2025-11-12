#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,arr[5001],f=1,s[5001];
long long mod=998244353,ans;
void dfs(int x,int y,int index){
	if(y==x){
		int num=0;
		for(int i=1;i<y;i++) num+=s[i];
		if(num>s[y]) ans++;
		ans%=mod;
		return;
	}
	for(int i=index;i<=n;i++){
		s[y+1]=arr[i];
		dfs(x,y+1,i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>1) f=0;
	}
	if(f){
		long long sum=2,num=n*(n-1);
		for(int i=3;i<=n;i++){
			sum*=i;
			sum%=mod;
			num*=(n-i+1);
			num%=mod;
			ans+=num/sum;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=3){
		sort(arr+1,arr+1+n);
		if(arr[1]+arr[2]>arr[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++) dfs(i,0,1);
	cout<<ans;
	return 0;
}
