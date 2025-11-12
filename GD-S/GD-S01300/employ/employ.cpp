#include<bits/stdc++.h>
using namespace std;
string t;
int a[1000001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m>>t;
	bool yes=1;
	for(int i:t){
		if(i!='1')yes=0; 
	}
	if(yes=1){
		long long ans=1,times=1;
		for(int i=1;i<=n;i++){
			ans*=times;
			times++;
			ans%=998244353;
		}
		cout<<ans<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
} 
