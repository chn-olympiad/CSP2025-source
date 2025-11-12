#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxn,ans,f,f2,f3;
void dfs(long long zh,long long k,long long maxnn,long long gs,long long x){
	if(gs>=3&&zh>(maxnn*2)&&x!=0){
		ans++;
		ans%=998244353;
	}
	if(k==n+1){
		return ;
	}
	dfs(zh+a[k],k+1,max(a[k],maxnn),gs+1,1);
	dfs(zh,k+1,maxnn,gs,0);
}
int main(){
//	freopen("D:\\number4.in","r",stdin);

	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	long long i,j;
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			maxn=114514;
		}
	}
	if(maxn!=114514){
		f=1;
		for(int m=1;m<=n;m++){
			for(i=2;i<=n;i++){
			f*=i;
			f%=998244353;
		}
		f2=1;
		for(i=2;i<=m;i++){
			f2*=i;
			f2%=998244353;
		}
		ans+=f/f2/f2;
		}
		
		cout<<ans<<endl; 
		return 0;
	}
	dfs(0,1,0,0,0);
	cout<<ans<<endl;
	return 0;
}
