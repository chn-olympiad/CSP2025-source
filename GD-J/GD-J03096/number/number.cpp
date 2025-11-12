#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	vector<long long>num;
	cin>>str;
	for(long long i=0;i<(long long)str.size();i++)
		if(str[i]>='0'&&str[i]<='9') num.push_back((str[i]-'0'));
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<(long long)num.size();i++)
		cout<<num[i];
	return 0;
}
