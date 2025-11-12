#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	const int MAXN=5e3+5;
	const int mod=998244353;
	int a[MAXN];
	int n;
	
	namespace Part1_10{//枚举子集 
		void solve(){
			int u=1<<n,cnt=0;
			for(int i=0;i<u;i++){
				//i为信息
				int sum=0,maxn=0,tot=0;
				for(int j=0;j<n;j++){
					if((1<<j)&i)sum+=a[j+1],maxn=max(maxn,a[j+1]),tot++;
				}
				if(tot<3)continue;
//				cout<<sum<<" "<<maxn<<endl;
				if(sum>2*maxn)cnt++;
			}
			cout<<cnt<<endl;
			return;
		}
	}
	namespace Part15_20{
		void solve(){
			long long times=1;
			long long ans=0;
			for(int i=n;i>=3;i--){
				times=(times*(n-i+1))%mod;
				ans=(ans+times)%mod;
			}
			cout<<mod<<endl;
			return;
		}
	}
	
	int main(){
		#ifndef debug
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		#endif
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		cin>>n;
		int maxn=0;
		for(int i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]);
		
		if(n<=20)Part1_10::solve();
		else if(maxn<=1)Part15_20::solve();
		else Part1_10::solve();
		return 0;
	}
}
int main(){
	zcy::main();
	return 0;
}
