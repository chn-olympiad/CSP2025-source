#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;
using LL = long long;
string s,x;
bool cmp(const char &x,const char &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>x;
	for(LL i=0;i<LL(x.size());i++){
		if(isdigit(x[i]))	s+=x[i];
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
