#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,Mod=998244353;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') f=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f==0){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ll)ans*i%Mod;
		}
		cout<<ans;
	}
	return 0;
}
