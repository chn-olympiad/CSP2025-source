#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,c[502],ans=1,c1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	long long n2=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) n2--;
		
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') c1++;
	}
	c1=n-n2;
	while(c1--){
		ans*=n2;
		n2--;
		ans=ans%998244353;
		cout<<ans<<endl;
	}
	cout<<ans%998244353;
	return 0;
}
