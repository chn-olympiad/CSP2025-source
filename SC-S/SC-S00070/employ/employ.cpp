#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501];
long long ck;
long long ans;
long long Mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<+n;i++){
		cin>>c[i];
	}
	if(m==1){
		ans=n;
		
	}
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			ck=1;
			break;
		}
	}
	if(!ck){
		ans=1;
		for(int i=n;i>=1;i--){
			ans=(ans*i)%Mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}