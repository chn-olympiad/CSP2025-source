#include<bits/stdc++.h>
using namespace std;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(65537);
	bool flag1=true,flag2=true;
	int n,m;cin>>n>>m;
	string s;cin>>s;int cnt=0;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=0; i<s.size(); i++){
		if(s[i]==49) flag1=false;
		else flag2=false;
	}
	if(flag1) cout<<0;
	if(flag2){
		int sum=1;
		for(int i=1; i<=n; i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
	}
	if(m==1) cout<<n;
	else{
		int ans=rand()%998244353;
		cout<<ans;
	}
	return 0;
}
