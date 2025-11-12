#include<bits/stdc++.h>
using namespace std;
const int N=5*1e3+5,mod=998244353;
long long ans=1,sum=0;
int l[N],he[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxx=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		maxx=max(l[i],maxx);
	}
	if(maxx==1){
		for(int i=3;i<=n;i++){
			ans=1;
			for(int j=n;j>=n-i+1;j--)
				ans=(ans*j)%mod;
			int ji=ans;
			ans=1;
			for(int j=1;j<=i;j++)
				ans=(ans*j)%mod;
			sum=sum+ji/ans;
		}
		cout<<sum;
		return 0;
	}else{
		sort(l+1,l+1+n);
		if(n<3){
			cout<<0;
			return 0;
		}else if(n==3){
			if(l[3]<l[2]+l[1])
				cout<<1;
			else
				cout<<0;
		}else{
			for(int i=3;i<=n;i++){
				ans=1;
				for(int j=n;j>=n-i+1;j--)
					ans=(ans*j)%mod;
				int ji=ans;
				ans=1;
				for(int j=1;j<=i;j++)
					ans=(ans*j)%mod;
				sum=sum+ji/ans;
			}
			cout<<sum;
		}
	}
	return 0;
}


