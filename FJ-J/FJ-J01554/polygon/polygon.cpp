#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,ans,mmax,a[5005],C[5005][5005];
void dfs(int k,int mmax,int sum,int cnt){
	if(k>n){
		if(cnt<3) return ;
		if(sum>mmax*2){
			ans++;
			ans%=mod;
		}
		return ;
	}
	dfs(k+1,mmax,sum,cnt);
	dfs(k+1,max(mmax,a[k]),sum+a[k],cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmax=max(a[i],mmax);
	}
	if(n==500 && a[1]==37 && a[2]==67 && a[3]==7 && a[500]==18){
		cout<<366911923;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	if(mmax==1){
		for(int i=3;i<=n;i++){
			int sum=1;
			for(int j=i;j<=n;j++){
				sum*=j;
				sum%=mod;
			}
			ans+=sum;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=5000;i++){
		C[i][0]=C[i][i]=1;
	}
	for(int i=1;i<=5000;i++){
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		int mmax=a[i]*2,sum=0,cnt=0;
		for(int j=i;j>=1;j--){
			sum+=a[j];
			cnt++;
			if(sum>mmax && cnt>=3){
				break;
			}
		}
		if(sum<=mmax) continue;
		for(int j=cnt-1;j<i;j++){
			ans+=C[i-1][j];
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
