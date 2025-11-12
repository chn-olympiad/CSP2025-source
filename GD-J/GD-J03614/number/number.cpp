#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> num;
	for(int i = 0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num.push_back(s[i] - '0');
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(auto i : num){
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//fucking CCF
