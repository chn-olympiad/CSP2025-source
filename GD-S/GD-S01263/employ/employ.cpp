#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
long long ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int n1=n;
	for(int i=1;i<=n;i++){
		if(c[i]==0)
			n1--;
	}
	if(m>n1){
		cout<<0;
		return 0;
	}
	for(int i=n1;i>=m;i--){
		long long num=1;
		for(int j=n;j>=n-i+1;j--)
			num=num*j%998244353;
		ans=(ans+num)%998244353;
	}
	cout<<ans;
	return 0;
}
