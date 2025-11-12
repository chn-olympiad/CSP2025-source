#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=1,num;
string s;
int p[105];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		int c;
		cin >> c;
		p[c]++;
	}
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
