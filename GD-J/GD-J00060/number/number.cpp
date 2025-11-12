#include<bits/stdc++.h>
using namespace std;
vector<int> d;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l;
	string s;
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			d.push_back(s[i]-48);
		}
	}
	sort(d.begin(),d.end(),cmp);
	for(int i=0;i<d.size();i++){
		cout<<d[i];
	}
	return 0;
}
