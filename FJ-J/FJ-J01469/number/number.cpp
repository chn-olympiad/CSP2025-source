#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string s;
vector<int> num;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')num.push_back(s[i]-'0');
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.size();i++)cout<<num[i];
	return 0;
}
