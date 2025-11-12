#include<bits/stdc++.h>
using namespace std;
int const N=998244353;
long long n,a[5005],maxn=-1,sum,vis[5005],ans,bz;
int cys(int x,int y){
	long long cnt=1;
	for(int i=2;i<=y;i++){
		cnt*=i;
		cnt%=N;
	}
	long long fma=1;
	for(int i=2;i<=y-x;i++){
		fma*=i;
		fma%=N;
	}
	long long fmb=1;
	for(int i=2;i<=x;i++){
		fmb*=i;
		fmb%=N;
	}
	cnt/=fma;
	cnt/=fmb;
	cnt%=N;
	return cnt;
}
void dfs(long long he,int cs,long long maz,int zs){
	//cout<<cs<<" "<<ans<<" "<<he<<" "<<maz<<" "<<zs<<" ";
	if(zs==bz){
		if(he>2*maz){
			ans++;
			ans%=N;
			return;
		}
		else return;
	}
	if(cs==n+1)return;
	for(int i=1;i<=2;i++){
		if(i==1&&vis[cs]==0){
			//cout<<1<<endl;
			vis[cs]=1;
			dfs(he+a[cs],cs+1,max(maz,a[cs]),zs+1);
			vis[cs]=0;
		}
		else {
			//cout<<0<<endl;
			dfs(he,cs+1,maz,zs);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		long long sum=0;
		for(int i=3;i<=n;i++){
			sum+=cys(i,n);
			sum%=N;
		}
		cout<<sum%N;
	}
	else{
		for(int i=3;i<=n;i++){
			ans=0;
			bz=i;
			dfs(0,1,-1,0);
			//cout<<ans<<endl;
			sum+=ans;
			sum%=N;
			//cout<<endl;
		}
		cout<<sum%N;
	} 
	return 0;
} 
