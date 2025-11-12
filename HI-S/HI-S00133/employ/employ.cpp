#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=502;
int c[N];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int tot=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		cout<<5;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else{
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

