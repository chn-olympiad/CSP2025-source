#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int p=998244353;
int n,m;
string s;
int b[510],c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		b[i+1]=s[i]-'0';
	}
	int ok=1,cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
		if(b[i]==0) ok=0;
	}
	if(ok){
		ll ans=1;
		for(int i=1;i<=n-cnt;i++){
			ans*=i;ans%=p;
		}
		cout<<ans;
		return 0;
	}	
}
