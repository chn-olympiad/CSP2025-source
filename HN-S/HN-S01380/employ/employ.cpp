#include<bits/stdc++.h>
using namespace std;

long long n,zong,ans=1;
char a[10000];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-'0'){
			zong++;
		}
	}
	
	cout<<bool(zong);
//	for(int i=1;i<=zong;i++){
//		ans*=i;
//		ans=ans%998244353;
//	}
//	
//	cout<<ans;
	return 0;
}
