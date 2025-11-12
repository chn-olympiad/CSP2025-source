#include<bits/stdc++.h>
using namespace std;
bool fd(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<long long> vec;
	for(int i=0;i<a.length();i++){
		long long t=a[i]-'0';
		if(a[i]>='0'&&a[i]<='9'){
			vec.push_back(t);
		}
	}
	long long an[1000005]={};
	for(int i=0;i<vec.size();i++){
		an[i]=vec[i];
	}
	sort(an,an+vec.size(),fd);
	for(int i=0;i<vec.size();i++){
		printf("%lld",an[i]);
	}
	return 0;
}
