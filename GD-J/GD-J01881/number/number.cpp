#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	vector<int> v;
	string s;
	cin >> s;
	for(auto &i : s){
		if(isdigit(i)){
			v.push_back(i-'0');
		}
	}
	
	sort(v.begin(),v.end(),[](int a,int b){
		return a > b;
	});
	
	for(auto &i : v) cout << i;
	
	cout << flush;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
