#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> all;
	for(char a : s){
		if(a == '1' or a == '2' or a == '3' or a == '4' or a == '5' or a == '6' or a == '7' or a == '8' or a == '9' or a == '0')
			all.push_back((int)a - 48);
	}
	sort(all.begin(),all.end());
	for(int i = all.size() - 1;i>=0;i--){
		cout<<all[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
