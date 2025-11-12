#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
vector<long long> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-48);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	return 0;
}
