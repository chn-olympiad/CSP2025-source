#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,a[505],zero,ans,d;
long long seat[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=1;
	for(long long i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
		cout<<ans<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

