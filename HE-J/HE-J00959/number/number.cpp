#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define con continue
using namespace std;
string s;
int a[27];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

