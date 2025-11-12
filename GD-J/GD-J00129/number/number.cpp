#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<windows.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> a;
	int n=s.size();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
