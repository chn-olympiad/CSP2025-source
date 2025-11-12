#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
int a[N],b[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0){
			sum++;
		}
	}
	long long ans = 1;
	if(n-ans+1<m){
		cout<<0;
		return 0;
	}
	else if(n-ans+1==m){
		for(int i = n-1;i>=(n-sum+1);i--){
			ans*=i;
			ans%=998244353;
		}
		for(int i = (n-sum);i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	else{
		for(int i = n;i>=(n-sum+1);i--){
			ans*=i;
			ans%=998244353;
		}
		for(int i = (n-sum);i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
