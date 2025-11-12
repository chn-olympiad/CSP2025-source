#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500005];string s;
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=1;
	for(int i=2;i<=n;i++){
			ans=ans*i%998244353;
		}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
