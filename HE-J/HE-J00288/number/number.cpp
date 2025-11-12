#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i] && s[i] <= '9'){
			//ÊÇÊý×Ö
			 a.push_back(int(s[i])-48);
		}	
	}
	
	sort(a.begin(),a.end(),cmp);
	
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
}

