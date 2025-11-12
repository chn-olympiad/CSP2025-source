#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s;
vector<int>a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//T1
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a.reserve(1000010);
	for(size_t i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(auto i=a.begin();i!=a.end();i++){
		cout<<*i;
	}
	return 0;
} 
