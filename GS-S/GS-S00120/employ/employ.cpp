#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			ans++;
		}
	}
	cout << ans;
	return 0;
}

