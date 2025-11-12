#include<bits/stdc++.h>
using namespace std;
long long ans=1,MOD=998244353,sum=0,anss=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int c[510];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	for(int i=1;i<=n;i++){
		if(sum>=c[i])sum++;
	}
	if((n-sum)<=m){
		anss++;
		anss%=MOD;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans-anss<<endl;
	return 0;
}
