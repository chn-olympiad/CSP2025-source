#include<bits/stdc++.h>
using namespace std;
vector<int>v;
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int k=s[i]-'0';
			v.push_back(k);
		}
	}
	sort(v.begin(),v.end(),cmp);
	int k=v.size();
	for(int i=0;i<k;i++){
		cout<<v[i];
	}
	return 0;
}
