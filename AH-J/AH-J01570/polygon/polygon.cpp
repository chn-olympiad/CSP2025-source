#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5005],ans,cnt;
void dfs(int now,int cnt1,int max1,int all){
	if(cnt1>=3 && all>2*max1){
		ans=(ans+1)%998244353;
	}
	for(int i=now+1;i<=n;i++){
		dfs(i,cnt1+1,max(max1,a[i]),all+a[i]);
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(!f){
		int ans=0;
		for(int i=3;i<=n;i++){
			long long x1=1;
			for(int j=1;j<=i;j++)x1=(x1*j)%998244353;
			long long x2=1;
			for(int j=n;j>n-i;j--)x2=(x2*j)%998244353;
			ans+=x2/x1;
		}
		cout<<ans;
	}else{
		dfs(0,0,0,0);
		cout<<ans;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
