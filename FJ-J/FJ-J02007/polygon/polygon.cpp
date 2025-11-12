#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int len[N];
long long ans1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i];
	}
	sort(len+1,len+n+1);
	int ans=0;
	if(n==3){
		int t=len[n];
		for(int i=1;i<=n;i++){
			ans+=len[i];
		}
		if(t*2<ans){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		int t1=n-2;
		for(int i=1;i<=n-2;i++){
			ans1=ans1+((i*t1%mod)%mod);
			t1--;
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				ans1=ans1+((n-j)%mod);
//			}
//		}
		cout<<ans1;
	}
}
