#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	int b=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			b=0;
			break;
		}
	}
	if(b){
		for(int i=n;i>1;i--) ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
