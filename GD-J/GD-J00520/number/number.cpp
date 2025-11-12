#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> a;
	cin>>s;
	for(char c:s){
		if(isdigit(c))a.push_back(c-48);
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int x:a)cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
