#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>a;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<(int)a.size();i++)cout<<a[i];
	return 0;
}
