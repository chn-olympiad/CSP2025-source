#include<bits/stdc++.h>
#define int long long
using namespace std;

int num[15];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch;
	while(cin>>ch){
		if('0'<=ch&&ch<='9'){
			num[(ch-'0')]++;
		}
	}
	for(int t=9;t>=0;t--){
		while(num[t]){
			cout<<t;
			num[t]--;
		}
	}
	
	return 0;
}