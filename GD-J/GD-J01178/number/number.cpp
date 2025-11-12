#include<bits/stdc++.h>
using namespace std;
#define int long long
string str;
vector<int>vec;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>str;
	for(char k:str){
		if(k>='0'&&k<='9')vec.push_back('0'-k);
	}
	sort(vec.begin(),vec.end());
	for(int k:vec)cout<<(-k);
	return 0;
}
