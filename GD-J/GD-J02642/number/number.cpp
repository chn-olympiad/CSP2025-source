#include<bits/stdc++.h>
#define int long long
using namespace std;
char a;
vector <int> v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin >> a){
		if(a >= '0' && a <= '9'){
			v.push_back(a-48);
		}
	}
	sort(v.begin(),v.end());
	for(int i = v.size()-1; i >= 0; i--){
		cout << v[i];
	}
	return 0;
} 
