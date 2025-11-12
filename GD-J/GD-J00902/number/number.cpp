#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> v;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(auto i : s)
		if(i >= '0' && i <= '9')
			v.push_back(i - '0');
	sort(v.rbegin(),v.rend());
	if(v.front() == 0)
		printf("0");
	else for(auto i : v)
		printf("%d",i);
	return 0;
} 
