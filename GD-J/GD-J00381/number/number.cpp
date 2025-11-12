#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int> v;
	for(int i = 0;i < s.size();i++) if(s[i] >= '0' && s[i] <= '9') v.push_back(s[i] - '0');
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i < v.size();i++) cout << v[i];
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
