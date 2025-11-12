#include<bits/stdc++.h>
using namespace std;
char t;
vector<long long> ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin >> t){
		if(t>='0'&&t<='9'){
			ans.push_back(t-'0');
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(long long i:ans){
		cout << i;
	}
}
