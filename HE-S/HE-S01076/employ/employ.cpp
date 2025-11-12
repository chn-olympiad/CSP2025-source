#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int len=s.size();
	bool flag=true;
	for(int i=0;i<len;i++){
		if (s[i]!='1'){
			flag=false;
		}
	}
	if (flag==true){
		long long ans=1,ans2=1;
		for(int i=1;i<=m;i++){
			ans*=i;
			ans%=998244353;
		}
		for(int i=1;i<=n;i++){
			ans2*=i;
			ans2%=998244353;
		}
		cout<<(ans+ans2)%998244353;
	}
	return 0;
}
