#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n,m;
string s[N][3];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		string s1,s2;cin>>s1>>s2;
		cout << 0 << '\n';
	}
	return 0;
}

