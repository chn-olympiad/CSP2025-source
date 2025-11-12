# include<bits/stdc++.h>
using namespace std;
long long a[5002],n,GD[5002],ans,ZY[5002];
void A(long long &a,long long b){a+=b;a-=a>=998244353?998244353:0;}
int min(int a,int b){return a<b?a:b;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		for(int j = a[i]+1;j<=5001;j++)A(ans,GD[j]);
		memset(ZY,0,sizeof(ZY));
		for(int j = 0;j<=5001;j++)A(ZY[min(5001ll,j+a[i])],GD[j]);
		for(int j = 1;j<i;j++)
		A(ZY[min(5001ll,a[j]+a[i])],1);
		for(int j = 0;j<=5001;j++)A(GD[j],ZY[j]);
	}
	cout<<ans%998244353;
	return 0;
} 
