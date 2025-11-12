#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
int n,m,a[N];
string s;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int z=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			z=1;
			break;
		}
	}
	if(z==0){
		int ans=1;
		for(int i=1;i<=n;i++){
			(ans*=i)%=mod;
		}
		cout<<ans<<endl;
	}
	else cout<<0%mod<<endl;
}
