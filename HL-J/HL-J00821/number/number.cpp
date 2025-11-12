#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> a;
	getline(cin,s);
	int I=0;
	for(int i = 0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
		a.push_back(s[i]-'0');
		I++;
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i = 0;i<I;i++){
		cout<<a[i];
	}
	//fclose(stdin);
	//#Shang4Shan3Ruo6Shui4
	//fclose(stdout);
	return 0;
}