#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long m,n,ans=1;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		ans=ans*(n-i);
	}
	ans=ans%998244353;
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

