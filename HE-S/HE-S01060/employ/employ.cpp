#include<bits/stdc++.h>
using namespace std;

const int N=998244353;
long long n,m,a[505],ans=1,f;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++) ans=(ans%N)*(i%N)%N;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=1;
			break;
		}
	}
	
	if(m==n and f==1) cout<<0;
	else if(f==0) cout<<ans%N;
	
	return 0;
}
