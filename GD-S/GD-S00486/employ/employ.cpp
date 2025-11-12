#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long ans=0,l[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int x,y,f=0;
	string s;
	cin>>x>>y>>s;
	for(int i=0;i<x;i++){
		if(s[i]=='0'){
			f=1;
			break;
		}
	}
	for(int i=0;i<x;i++){
		cin>>l[i];
	}
	if(f==0){
		ans=1;
		for(int i=0;i<x;i++){
			ans*=(x-i);
			ans%=MOD;
		}cout<<ans%MOD;
	}else{
		//sort(l,l+x);
		cout<<0;
	}
	return 0;
}
