#include<bits/stdc++.h>
using namespace std;
long long t,n,b[100010],dp[100010][4],d[100010],tot[100010],a[100010][4],n1,n2,n3,ans;
void dfs(long long k,long long n1,long long n2,long long n3,long long x){
	if((n1>n/2)||(n2>n/2)||(n3>n/2))return;
	if(tot[n]-tot[k-1]+x<ans)return;
	if(k==n+1){
		ans=max(ans,x);
		//for(int i=1;i<=n;i++)cout<<d[i]<<' ';
		//cout<<endl<<x<<endl;
		return;
	}
	//cerr<<"dfs"<<k<<endl;

	d[k]=1;
	dfs(k+1,n1+1,n2,n3,x+a[k][1]);
	d[k]=2;
	dfs(k+1,n1,n2+1,n3,x+a[k][2]);
	d[k]=3;
	dfs(k+1,n1,n2,n3+1,x+a[k][3]);
	d[k]=0;
}
void dfs1(long long k,long long n1,long long n2,long long x){
	if((n1>n/2)||(n2>n/2))return;
	if(tot[n]-tot[k-1]+x<ans)return;
	if(k==n+1){
		ans=max(ans,x);
		//for(int i=1;i<=n;i++)cout<<d[i]<<' ';
		//cout<<endl<<x<<endl;
		return;
	}
	//cerr<<"dfs"<<k<<endl;

	d[k]=1;
	dfs(k+1,n1+1,n2,n3,x+a[k][1]);
	d[k]=2;
	dfs(k+1,n1,n2+1,n3,x+a[k][2]);
	d[k]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		//cerr<<t<<endl;
		cin>>n;
		//memset(a,0,sizeof(a));
		bool a2=0,a3=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a2|=a[i][2];
			a3|=a[i][3];
			tot[i]=tot[i-1]+max(a[i][1],max(a[i][2],a[i][3]));
		}
		if(a2==0&&a3==0){
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1,greater<int>());
			for(int i=1;i<=n/2;i++)ans+=b[i];
			cout<<ans<<endl;
			continue;
		}else if(a3==0){
			dfs1(1,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
