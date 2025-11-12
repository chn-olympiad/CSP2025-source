#include<bits/stdc++.h> 
using namespace std;
namespace A{
	int n,a[5010],ans,maxx;
	void dfs(){
		 
	}
	int main(){
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		if(maxx==1){
			for(int i=3;i<=n;i++){
				int x=1;
				for(int j=i+1;j<=n;j++){
					x*=j;
					x%=998244353;
				}
				ans+=x;
				ans%=998244353;
			}
			cout<<ans;
			return 0;
		}
		if(n<=2){
			cout<<0;
			return 0;
		}
		if(n==3){
			if(a[1]+a[2]+a[3]>2*maxx){
				cout<<1;
			} 
			else{
				cout<<0;
			}
			return 0;
		}
		if(n<=500){
			for(int i=3;i<=n;i++){
				int x=1,y=0;
				for(int j=i+1;j<=n;j++){
					y+=a[j];
					x*=j;
					x%=998244353;
				}
				if(y>2*maxx){
					ans+=x;
					ans%=998244353;
				}
			}
			cout<<ans;
			return 0;
		}
		return 0;
	}
}
int main(){
	return A::main();
}