#include <bits/stdc++.h>
using namespace std;
const long long N=6000;
long long mod=998244353;
long long n,ans,maxs,a[N],sum,vis[N],t,ta,cha;
void find(long long shu,long long s,long long ma,long long ii){
	if(shu==0){
		if(ma*2<s){
//			cout<<"   ";
//			cout<<s<<" "<<ma<<" "<<ans<<endl;
			ans=((ans%mod)+1)%mod;
			ans=ans%mod;
		}
		return;
	}
	for(int j=ii;j<=n;j=j+1){
		if(vis[j]==0){
			vis[j]=1;
			s+=a[j];
			t=a[j];
//			cout<<a[j]<<" ";
			ta=ma;
			
			ma=max(a[j],ma);
			find(shu-1,s,ma,j);
			vis[j]=0;
			s-=a[j];
			ma=ta;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int bj=0;
	for(int i=1;i<=n;i=i+1){
		cin>>a[i];
	}
	for(int i=3;i<=n;i=i+1){
		for(int j=1;j<=n;j=j+1){
			vis[j]=0;
		}
		maxs=-10;
		sum=0;
		find(i,sum,maxs,1);
	}
	cout<<ans<<endl;
	return 0;
}
