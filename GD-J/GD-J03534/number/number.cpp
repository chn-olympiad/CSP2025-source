#include<bits/stdc++.h>
using namespace std;
#define int long long
string x;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>x;
	for(char i='9';i>='0';i--){
		int k=0;
		for(int j=0;j<x.size();j++) if(x[j]==i) k++;
		while(k--) cout<<i; 
	}
	return 0;
}
