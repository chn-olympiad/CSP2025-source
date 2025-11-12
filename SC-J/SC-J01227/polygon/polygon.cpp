#include<bits/stdc++.h>
using namespace std;
int a[5005];
const int mod=998244353;
long long ans=0;
int n;
void dfs(int x,int sum){
	if(x>n) return;
	if(sum>a[x]&&x>=3){
		ans++;
		ans%=mod;
	}
	dfs(x+1,sum+a[x]);
	dfs(x+1,sum);
}
long long C(int x,int y){
	long long res=1;
	int i=y,j=1;
	while(i>=x+1){
		res*=i;
		i--;
		while(res%j==0&&j<=y-x){
			res/=j;
			j++;
		}
		res%=mod;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f1=0;
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0);
		cout<<ans<<'\n';
		return 0;
	}
	else{
		long long sum=0;
		for(int i=3;i<=n;i++){
			for(int j=2;j<=i-1;j++){
				sum+=C(j,i-1);
				sum%=mod;
			}
		}
		cout<<sum<<'\n';
		return 0;
	}
	return 0;
}//40+24