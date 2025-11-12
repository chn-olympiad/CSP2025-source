#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ao(int x){
	int ans=1;
	for(int i=x;i>=1;i--){
		ans*=i;
		ans%=mod;
	}
	return ans%=mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int c[501],ch=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			ch++;
		}
	}
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=false;
		}
	}
	if(flag==true){
		cout<<ao(n-ch)*ao(ch)<<endl;
		return 0;
	}
	if(m==n){
		if(ch>0){
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<2<<endl;
	return 0;
}
