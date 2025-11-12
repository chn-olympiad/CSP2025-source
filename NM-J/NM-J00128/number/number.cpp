#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
bool fun(int a,int b){
	return a>b;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s1 = {};
	cin>>s1;
	vector<long long> vec1;
	for(long long i = 0;i<s1.length();i++){
		if(s1[i] >= '0' && s1[i] <= '9'){
			long long t = s1[i]-'0';
			vec1.push_back(t);
		}
	}
	sort(vec1.begin(),vec1.end(),fun);
	for(long long i = 0;i<vec1.size();i++){
		printf("%lld",vec1[i]);
	}
	
	return 0;
}
