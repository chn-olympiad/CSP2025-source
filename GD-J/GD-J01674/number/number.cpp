#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	char s;
	vector<int>num;
	while(cin>>s){
		if(s>='0'&&s<='9'){
			num.push_back(s-'0');
		}
		
	}
	sort(num.begin(),num.end(),greater<int>());
	
	for(auto i:num){
		cout<<i;
	}
	
	
	
	
	return 0;
}
