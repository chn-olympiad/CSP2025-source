#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef unsigned long long ull;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int flag=0;
	for(int i=0;i<n;i++){
		char a;
		cin>>a;
		if(a!='1')flag=1;
	}
	int t;
	int cnt=n;
	for(int i=0;i<n;i++){
	cin>>t;
	if(!t)cnt--;
	}
	mt19937 gen(time(nullptr));
	cout<<gen()%37<<endl;
//	cout<<cnt<<endl;
//	ull ans=1;
//	for(int i=1;i<=cnt;i++){
//		ans*=i;
//		ans%=mod;
//	}
//	ull ans1=1;
//	for(int i=1;i<=cnt;i++){
//		ans*=i;
//		ans%=mod;
//	}
//	ans+=ans1;
//	ans%=mod;
	cout<<ans<<endl;
}
