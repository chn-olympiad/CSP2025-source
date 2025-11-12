#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<int> num;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9') num.push_back(a[i]-'0');
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.size();i++) cout<<num[i];
	return 0;
}