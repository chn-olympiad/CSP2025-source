#include<bits/stdc++.h>
using namespace std;
long long a[50005],n,b[50005],an;
bool flag,vis[50005];
bool cmp(long long x,long long y){
	return x>y;
}
long long che(long long x){
	long long ans=0,ans1=1,ans2=1;
	for(long long i=3;i<=n;i++){
		ans1=1;
		for(long long j=i+1;j<=n;j++)ans1=ans1*j/(j-i)%998244353;
		ans=(ans+ans1)%998244353;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=1;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])cout<<1;
		else cout<<0;
	}else{
		cout<<che(3);						
	}
	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
}

