#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
int a[N];
string s;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(auto ch:s){ 
		if(ch>='0'&&ch<='9') a[ch-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++) cout<<i;
	}
	return 0;
}
