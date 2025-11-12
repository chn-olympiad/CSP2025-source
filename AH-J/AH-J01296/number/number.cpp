#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string a;
int t[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a;
	for(int i=0;i<(long long)a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
//diyitimiaole
