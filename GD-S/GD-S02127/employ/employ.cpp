#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isa=true;
int n,m;
int c[1000],a[1000];
string s;
int jiech(int n){
	ll ans=n; 
	int cnt = n-1;
	while(cnt>=1){
		ans*=cnt;
		ans%=99824453;
		cnt--;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
		if(a[i+1]==0) isa=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(isa) cout<<jiech(n);
	return 0;
}
