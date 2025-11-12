#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],bl1,cl2,ans,k;
void dfs(int x,int sum){
	if(x==n+1){
		if(bl1>cl2){
			ans++;
			ans%=mod;
		}return ;
	}
	int cl1=n-x+1;
	if(sum==k) dfs(x+1,sum);
	else if(sum+cl1==k){
		bool bd1=(sum<k-1);
		if(bd1) bl1+=a[x];
		else cl2=a[x];
		dfs(x+1,sum+1);
		if(sum<k-1) bl1-=a[x];
	}else{
		dfs(x+1,sum);
		bool bd1=(sum<k-1);
		if(bd1) bl1+=a[x];
		else cl2=a[x];
		dfs(x+1,sum+1);
		if(sum<k-1) bl1-=a[x];
	}
}int c(int m,int j){
	int sum=1;
	for(int i=m;i>=2;i--) sum*=i;
	for(int i=2;i<=j;i++) sum/=i;
	for(int i=2;i<=m-j;i++) sum/=i;
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=0;
	}if(f){
		for(int i=3;i<=n;i++) ans+=c(n,i);
		cout<<ans;
		return 0;
	}sort(a+1,a+n+1);
	for(k=3;k<=n;k++){
		dfs(1,0);
	}cout<<ans;
	return 0;
}
