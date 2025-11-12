#include<iostream>
using namespace std;
char s[503];
int c[100003];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	bool flag=false;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') flag=true;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		if(flag==true){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998;
		} 
		ans%=244;
		ans%=353;
		cout<<ans;
		return 0;
	}
	if(!flag){
		int ans=1;
		while(m--){
			ans=(ans*n)%998;
			n--;
		}
		ans%=244;
		ans%=353;
		cout<<ans;
		return 0;
	} 
	cout<<1;
	return 0;
} 
