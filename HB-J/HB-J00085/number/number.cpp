#include<bits/stdc++.h>

using namespace std;

string s;
vector<int>v;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int x=0;x<s.size();x++){
		if(s[x]>='0' && s[x]<='9'){
			v.push_back(s[x]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int x=0;x<v.size();x++){
		cout<<v[x];
	}
	return 0;
}

