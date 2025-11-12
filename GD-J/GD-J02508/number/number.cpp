#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int>a;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			a.push_back(s[i]-'0');
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0){
		cout << 0;
		return 0;
	}
	for(int i=0;i<a.size();i++) cout << a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

